/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:48:20 by habe              #+#    #+#             */
/*   Updated: 2025/09/16 17:41:20 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	close_files(t_px *px)
{
	close_safe(&px->fd_in);
	close_safe(&px->fd_out);
}

static int	cmd_all_set(t_cmd *c1, t_cmd *c2, char **cmd, \
		char *const envp[])
{
	if (cmd_init(c1, cmd[0], envp) != 0)
		return (1);
	if (cmd_init(c2, cmd[1], envp) != 0)
	{
		free_split(c1->argv);
		if (c1->path != NULL)
			free(c1->path);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	c1;
	t_cmd	c2;
	t_px	px;
	int		st;

	px.fd_in = -1;
	px.fd_out = -1;
	if (argc != 5)
		usage_print_exit();
	if (cmd_all_set(&c1, &c2, &argv[2], envp) != 0)
		return (0);
	open_infile(&px, argv[1]);
	open_outfile(&px, argv[4]);
	st = connect_pipe(&px, &c1, &c2, envp);
	close_files(&px);
	free_all(&c1, &c2);
	return (st);
}

// // cmd_init_test.c
// #include <unistd.h>   // write
// #include <stdlib.h>   // EXIT_*

// // ------------- tiny I/O helpers (Norm向けに短く) -------------
// static void	putstr_fd(const char *s, int fd)
// {
// 	size_t	i;

// 	if (!s)
// 		return ;
// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	(void)write(fd, s, i);
// }

// static void	putendl_fd(const char *s, int fd)
// {
// 	putstr_fd(s, fd);
// 	(void)write(fd, "\n", 1);
// }

// static void	print_cmd(const char *label, const t_cmd *c)
// {
// 	int	i;

// 	putstr_fd(label, 1);
// 	putendl_fd(":", 1);
// 	putstr_fd("  path: ", 1);
// 	if (c->path)
// 		putendl_fd(c->path, 1);
// 	else
// 		putendl_fd("(null)", 1);
// 	putendl_fd("  argv:", 1);
// 	if (!c->argv)
// 	{
// 		putendl_fd("    (null)", 1);
// 		return ;
// 	}
// 	i = 0;
// 	while (c->argv[i] != NULL)
// 	{
// 		putstr_fd("    [", 1);
// 		putstr_fd(c->argv[i], 1);
// 		putendl_fd("]", 1);
// 		i++;
// 	}
// }

// // ------------- main: "cmd1" "cmd2" を受け取って検証 -------------
// int	main(int argc, char **argv, char **envp)
// {
// 	t_cmd	c1;
// 	t_cmd	c2;
// 	int		rc1;
// 	int		rc2;

// 	if (argc != 3)
// 	{
// 		putendl_fd("Usage: ./cmd_init_test \"cmd1\" \"cmd2\"", 2);
// 		return (EXIT_FAILURE);
// 	}
// 	rc1 = cmd_init(&c1, argv[1], envp);
// 	rc2 = cmd_init(&c2, argv[2], envp);
// 	putendl_fd("== cmd_init results ==", 1);
// 	putstr_fd("cmd1 rc = ", 1); putendl_fd(rc1 == 0 ? "0 (OK)" : "-1 (NG)", 1);
// 	putstr_fd("cmd2 rc = ", 1); putendl_fd(rc2 == 0 ? "0 (OK)" : "-1 (NG)", 1);
// 	putendl_fd("", 1);
// 	print_cmd("cmd1", &c1);
// 	print_cmd("cmd2", &c2);
// 	return ((rc2 == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
// }
