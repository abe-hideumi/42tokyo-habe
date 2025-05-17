/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owner <owner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:50:36 by habe              #+#    #+#             */
/*   Updated: 2025/05/08 18:22:24 by owner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

// int	main(void)
// {
// 	// ft_atoi
// 	printf("ft_atoi(\"  -42abc\") = %d\n\n", ft_atoi("  -42abc"));

// 	// ft_bzero
// 	char b[5] = "abcd";
// 	ft_bzero(b, 2);
// 	printf("ft_bzero: [%c][%c][%c][%c]\n\n", b[0], b[1], b[2], b[3]);

// 	// ft_calloc
// 	char *c = (char *)ft_calloc(5, sizeof(char));
// 	if (c)
// 	{
// 		strcpy(c, "1234");
// 		printf("ft_calloc: %s\n\n", c);
// 		free(c);
// 	}

// 	return (0);
// }


// int	main(void)
// {
// 	// ft_isalnum
// 	printf("ft_isalnum('a') = %d\n\n", ft_isalnum('a'));
// 	printf("ft_isalnum('1') = %d\n\n", ft_isalnum('1'));
// 	printf("ft_isalnum('@') = %d\n\n", ft_isalnum('@'));

// 	// ft_isalpha
// 	printf("ft_isalpha('a') = %d\n\n", ft_isalpha('a'));
// 	printf("ft_isalpha('1') = %d\n\n", ft_isalpha('1'));

// 	// ft_isascii
// 	printf("ft_isascii('A') = %d\n\n", ft_isascii('A'));
// 	printf("ft_isascii(128) = %d\n\n", ft_isascii(128));

// 	// ft_isdigit
// 	printf("ft_isdigit('3') = %d\n\n", ft_isdigit('3'));
// 	printf("ft_isdigit('x') = %d\n\n", ft_isdigit('x'));

// 	// ft_isprint
// 	printf("ft_isprint(' ') = %d\n\n", ft_isprint(' '));
// 	printf("ft_isprint('\\n') = %d\n\n", ft_isprint('\n'));
// 	printf("ft_isprint('A') = %d\n\n", ft_isprint('A'));

// 	return (0);
// }


// int	main(void)
// {
// 	// ft_memchr
// 	char mem1[] = "abcdef";
// 	printf("ft_memchr(\"abcdef\", 'd', 6) = %s\n\n", (char *)ft_memchr(mem1, 'd', 6));

// 	// ft_memcmp
// 	printf("ft_memcmp(\"abc\", \"abd\", 2) = %d\n\n", ft_memcmp("abc", "abd", 2));
// 	printf("ft_memcmp(\"abc\", \"abd\", 3) = %d\n\n", ft_memcmp("abc", "abd", 3));

// 	// ft_memcpy
// 	char mcpy[6] = "12345";
// 	ft_memcpy(mcpy, "abcde", 5);
// 	printf("ft_memcpy = %s\n\n", mcpy);

// 	// ft_memmove
// 	char mmove[] = "abcdef";
// 	ft_memmove(mmove + 2, mmove, 4); // overlap test
// 	printf("ft_memmove = %s\n\n", mmove);

// 	// ft_memset
// 	char mset[6] = "12345";
// 	ft_memset(mset, 'A', 3);
// 	printf("ft_memset = %s\n\n", mset);

// 	return (0);
// }


// int	main(void)
// {
// 	// ft_strchr
// 	char str1[] = "Hello, world!";
// 	printf("ft_strchr(\"Hello, world!\", 'o') = %s\n\n", ft_strchr(str1, 'o'));

// 	// ft_strdup
// 	char str2[] = "Hello, world!";
// 	char *dup = ft_strdup(str2);
// 	printf("ft_strdup(\"Hello, world!\") = %s\n\n", dup);
// 	free(dup); // strdupで確保したメモリを解放

// 	// ft_strlcat
// 	char str3[20] = "Hello, ";
// 	char str4[] = "world!";
// 	printf("ft_strlcat(str3, \"world!\", 20) = %lu, result = %s\n\n", ft_strlcat(str3, str4, 20), str3);

// 	// ft_strlcpy
// 	char str5[20] = "Hello, ";
// 	char str6[] = "world!";
// 	printf("ft_strlcpy(str5, \"world!\", 20) = %lu, result = %s\n\n", ft_strlcpy(str5, str6, 20), str5);

// 	// ft_strlen
// 	char str7[] = "Hello, world!";
// 	printf("ft_strlen(\"Hello, world!\") = %zu\n\n", ft_strlen(str7));

// 	// ft_strncmp
// 	char str8[] = "Hello";
// 	char str9[] = "Hellz";
// 	printf("ft_strncmp(\"Hello\", \"Hellz\", 4) = %d\n\n", ft_strncmp(str8, str9, 4));
// 	printf("ft_strncmp(\"Hello\", \"Hellz\", 5) = %d\n\n", ft_strncmp(str8, str9, 5));

// 	// ft_strnstr
// 	char str10[] = "Hello, world!";
// 	char str11[] = "world";
// 	printf("ft_strnstr(\"Hello, world!\", \"world\", 13) = %s\n\n", ft_strnstr(str10, str11, 13));

// 	// ft_strrchr
// 	char str12[] = "Hello, world!";
// 	printf("ft_strrchr(\"Hello, world!\", 'o') = %s\n\n", ft_strrchr(str12, 'o'));

// 	return (0);
// }


// int	main(void)
// {
// 	char	c;

// 	// 英大文字 → 小文字に変換
// 	c = 'A';
// 	printf("ft_tolower('%c') = '%c'\n\n", c, ft_tolower(c));

// 	// 英小文字 → 小文字（変化なし）
// 	c = 'b';
// 	printf("ft_tolower('%c') = '%c'\n\n", c, ft_tolower(c));

// 	// 非英字 → 変化なし
// 	c = '1';
// 	printf("ft_tolower('%c') = '%c'\n\n", c, ft_tolower(c));

// 	// 英小文字 → 大文字に変換
// 	c = 'z';
// 	printf("ft_toupper('%c') = '%c'\n\n", c, ft_toupper(c));

// 	// 英大文字 → 大文字（変化なし）
// 	c = 'G';
// 	printf("ft_toupper('%c') = '%c'\n\n", c, ft_toupper(c));

// 	// 記号 → 変化なし
// 	c = '!';
// 	printf("ft_toupper('%c') = '%c'\n\n", c, ft_toupper(c));

// 	return (0);
// }


// void print_split(char **split)
// {
// 	int i = 0;
// 	if (!split)
// 	{
// 		printf("split returned NULL\n");
// 		return;
// 	}
// 	while (split[i])
// 	{
// 		printf("split[%d] = \"%s\"\n", i, split[i]);
// 		i++;
// 	}
// 	printf("split[%d] = NULL\n", i); // 終端NULLの確認
// }

// int main(void)
// {
// 	char **result;

// 	// テストケース① 普通の文字列
// 	result = ft_split("hello world split test", ' ');
// 	printf("Test 1:\n");
// 	print_split(result);

// 	// テストケース② 区切り連続
// 	result = ft_split("  split   this  text ", ' ');
// 	printf("\nTest 2:\n");
// 	print_split(result);

// 	// テストケース③ 空文字列
// 	result = ft_split("", ' ');
// 	printf("\nTest 3:\n");
// 	print_split(result);

// 	// テストケース④ 区切りのみ
// 	result = ft_split("      ", ' ');
// 	printf("\nTest 4:\n");
// 	print_split(result);

// 	// テストケース⑤ NULL入力
// 	result = ft_split(NULL, ' ');
// 	printf("\nTest 5:\n");
// 	print_split(result);

// 	return 0;
// }