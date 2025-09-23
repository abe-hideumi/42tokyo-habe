#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'
NC='\033[0m'

PIPEX="./pipex"

# テスト結果を記録（shell比較付き）
run_test_with_comparison() {
    local test_name="$1"
    local description="$2"
    local infile="$3"
    local cmd1="$4"
    local cmd2="$5"
    local outfile="$6"

    echo -e "${CYAN}=== $test_name ===${NC}"
    echo -e "${YELLOW}説明: $description${NC}"
    echo -e "${BLUE}コマンド: $PIPEX $infile \"$cmd1\" \"$cmd2\" $outfile${NC}"

    # pipex実行
    echo -e "${MAGENTA}--- PIPEX実行 ---${NC}"
    local pipex_error
    pipex_error=$($PIPEX "$infile" "$cmd1" "$cmd2" "$outfile" 2>&1)
    local pipex_exit=$?

    echo -e "${GREEN}pipexエラーメッセージ:${NC}"
    if [ -n "$pipex_error" ]; then
        echo "$pipex_error"
    else
        echo "(なし)"
    fi
    echo -e "${GREEN}pipex終了ステータス: $pipex_exit${NC}"

    # shell実行（可能な場合のみ）
    echo -e "${MAGENTA}--- SHELL比較 ---${NC}"
    if [ -f "$infile" ] || [ "$infile" = "/dev/null" ]; then
        local shell_error
        shell_error=$(bash -c "< \"$infile\" $cmd1 | $cmd2 > shell_$outfile" 2>&1)
        local shell_exit=$?

        echo -e "${GREEN}shell終了ステータス: $shell_exit${NC}"
        if [ -n "$shell_error" ]; then
            echo -e "${GREEN}shellエラーメッセージ:${NC}"
            echo "$shell_error"
        fi

        # 終了ステータス比較
        if [ "$pipex_exit" -eq "$shell_exit" ]; then
            echo -e "${GREEN}✓ 終了ステータス一致${NC}"
        else
            echo -e "${RED}✗ 終了ステータス不一致 (pipex: $pipex_exit, shell: $shell_exit)${NC}"
        fi
        rm -f "shell_$outfile"
    else
        echo -e "${YELLOW}shell比較スキップ (入力ファイル問題)${NC}"
    fi

    echo ""
    rm -f "$outfile"
}

# 単純テスト（shell比較なし）
run_simple_test() {
    local test_name="$1"
    local description="$2"
    shift 2
    local cmd=("$@")

    echo -e "${CYAN}=== $test_name ===${NC}"
    echo -e "${YELLOW}説明: $description${NC}"
    echo -e "${BLUE}実行: ${cmd[*]}${NC}"

    local error_output
    error_output=$({"${cmd[@]}"} 2>&1)
    local exit_code=$?

    echo -e "${GREEN}エラーメッセージ:${NC}"
    if [ -n "$error_output" ]; then
        echo "$error_output"
    else
        echo "(なし)"
    fi
    echo -e "${GREEN}終了ステータス: $exit_code${NC}"
    echo ""

    rm -f test_output.txt
}

# テスト用ファイル準備
setup_test_files() {
    echo -e "${BLUE}=== テスト環境準備 ===${NC}"

    # 正常な入力ファイル
    echo "Test line 1" > normal_input.txt
    echo "Test line 2" >> normal_input.txt

    # 権限なし入力ファイル
    echo "No read permission" > no_read_input.txt
    chmod 000 no_read_input.txt

    # 権限なし実行ファイル
    echo '#!/bin/bash' > no_exec_cmd.sh
    echo 'echo "This should not execute"' >> no_exec_cmd.sh
    chmod 644 no_exec_cmd.sh  # 読み書きのみ

    # 実行可能なスクリプト（比較用）
    echo '#!/bin/bash' > exec_cmd.sh
    echo 'cat' >> exec_cmd.sh
    chmod 755 exec_cmd.sh

    # 権限なしディレクトリ
    mkdir -p no_write_dir
    chmod 555 no_write_dir

    echo "準備完了:"
    ls -la normal_input.txt no_read_input.txt no_exec_cmd.sh exec_cmd.sh
    ls -ld no_write_dir
    echo ""
}

echo -e "${BLUE}======= PIPEX 完全エラーテスト + SHELL比較 =======${NC}"

if [ ! -f "$PIPEX" ]; then
    echo -e "${RED}エラー: $PIPEX が見つかりません${NC}"
    exit 1
fi

setup_test_files

echo -e "${YELLOW}=== 1. 基本的な126エラーケース（権限なし） ===${NC}"

# cmd2で126エラー（最も重要）
run_test_with_comparison "1-1" "cmd2が実行権限なし → 126" \
    "normal_input.txt" "cat" "./no_exec_cmd.sh" "test_output.txt"

# cmd1で126エラー（cmd2が成功すれば0になる）
run_test_with_comparison "1-2" "cmd1が実行権限なし + cmd2正常 → 0" \
    "normal_input.txt" "./no_exec_cmd.sh" "wc -l" "test_output.txt"

# 両方126エラー
run_test_with_comparison "1-3" "cmd1,cmd2両方実行権限なし → 126" \
    "normal_input.txt" "./no_exec_cmd.sh" "./no_exec_cmd.sh" "test_output.txt"

echo -e "${YELLOW}=== 2. 基本的な127エラーケース（存在しない） ===${NC}"

# cmd2で127エラー
run_test_with_comparison "2-1" "cmd2が存在しない → 127" \
    "normal_input.txt" "cat" "nonexistent_cmd2" "test_output.txt"

# cmd1で127エラー（cmd2が成功すれば0になる）
run_test_with_comparison "2-2" "cmd1が存在しない + cmd2正常 → 0" \
    "normal_input.txt" "nonexistent_cmd1" "wc -l" "test_output.txt"

# 両方127エラー
run_test_with_comparison "2-3" "cmd1,cmd2両方存在しない → 127" \
    "normal_input.txt" "nonexistent_cmd1" "nonexistent_cmd2" "test_output.txt"

echo -e "${YELLOW}=== 3. 126と127の混合ケース ===${NC}"

run_test_with_comparison "3-1" "cmd1=存在しない, cmd2=権限なし → 126" \
    "normal_input.txt" "nonexistent_cmd1" "./no_exec_cmd.sh" "test_output.txt"

run_test_with_comparison "3-2" "cmd1=権限なし, cmd2=存在しない → 127" \
    "normal_input.txt" "./no_exec_cmd.sh" "nonexistent_cmd2" "test_output.txt"

echo -e "${YELLOW}=== 4. ファイルアクセスエラーとの組み合わせ ===${NC}"

# infileエラー + cmd2権限なし
run_test_with_comparison "4-1" "存在しないinfile + cmd2権限なし → 126" \
    "nonexistent_input.txt" "cat" "./no_exec_cmd.sh" "test_output.txt"

# outfileエラー + cmd2権限なし
run_test_with_comparison "4-2" "cmd2権限なし + outfile権限なし → 126" \
    "normal_input.txt" "cat" "./no_exec_cmd.sh" "no_write_dir/output.txt"

echo -e "${YELLOW}=== 5. 特殊なケース ===${NC}"

# 絶対パスで権限なし
cp no_exec_cmd.sh /tmp/no_exec_abs.sh 2>/dev/null || sudo cp no_exec_cmd.sh /tmp/no_exec_abs.sh 2>/dev/null
chmod 644 /tmp/no_exec_abs.sh 2>/dev/null
run_test_with_comparison "5-1" "絶対パスで権限なし → 126" \
    "normal_input.txt" "cat" "/tmp/no_exec_abs.sh" "test_output.txt"

# ディレクトリを実行しようとする
run_test_with_comparison "5-2" "ディレクトリを実行 → 126" \
    "normal_input.txt" "cat" "./no_write_dir" "test_output.txt"

echo -e "${YELLOW}=== 6. 引数エラー ===${NC}"

run_simple_test "6-1" "引数不足" \
    $PIPEX "input.txt" "cat"

run_simple_test "6-2" "引数過多" \
    $PIPEX "input.txt" "cat" "wc" "output.txt" "extra"

echo -e "${YELLOW}=== 7. 複雑な実際使用例比較 ===${NC}"

# より実際的なコマンド
run_test_with_comparison "7-1" "実際的な例: ls権限なし" \
    "normal_input.txt" "cat" "./no_exec_cmd.sh" "test_output.txt"

run_test_with_comparison "7-2" "実際的な例: grep+権限なしwc" \
    "normal_input.txt" "grep line" "./no_exec_cmd.sh" "test_output.txt"

echo -e "${YELLOW}=== 8. エッジケース ===${NC}"

# 空のコマンド名（もし実装されていれば）
run_simple_test "8-1" "空のコマンド名" \
    $PIPEX "normal_input.txt" "" "wc -l" "test_output.txt"

run_simple_test "8-2" "空白のみのコマンド名" \
    $PIPEX "normal_input.txt" "   " "wc -l" "test_output.txt"

echo -e "${BLUE}=== まとめ表 ===${NC}"
echo "期待される終了ステータス:"
echo "  0: 正常終了、またはcmd1失敗+cmd2成功"
echo "  1: ファイルアクセスエラー、引数エラー"
echo "126: コマンドは存在するが実行できない（権限なし等）"
echo "127: コマンドが見つからない"

echo -e "${BLUE}=== クリーンアップ ===${NC}"
chmod 644 no_read_input.txt 2>/dev/null
chmod 755 no_write_dir 2>/dev/null
rm -f normal_input.txt no_read_input.txt no_exec_cmd.sh exec_cmd.sh
rm -f /tmp/no_exec_abs.sh 2>/dev/null
rm -rf no_write_dir
rm -f test_output.txt shell_test_output.txt

echo -e "${GREEN}すべてのテストが完了しました！${NC}"
