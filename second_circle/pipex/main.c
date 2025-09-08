/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:48:20 by habe              #+#    #+#             */
/*   Updated: 2025/09/08 18:41:58 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	main(int argc, char **argv, char **envp)
// {
// 	t_cmd	cmd1;
// 	t_cmd	cmd2;

// 	if (argc != 5)
// 		usage_print_exit();
// 	if (cmd_init(&cmd1, argv[2], envp) != 0)
// 		return (0);
// 	if (cmd_init(&cmd2, argv[3], envp) != 0)
// 		return (0);
// 	free_all(cmd1.argv, cmd2.argv);
// 	return (0);
// }

// cmd_init_test.c
#include <unistd.h>   // write
#include <stdlib.h>   // EXIT_*

// ------------- tiny I/O helpers (Norm向けに短く) -------------
static void	putstr_fd(const char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
		i++;
	(void)write(fd, s, i);
}

static void	putendl_fd(const char *s, int fd)
{
	putstr_fd(s, fd);
	(void)write(fd, "\n", 1);
}

static void	print_cmd(const char *label, const t_cmd *c)
{
	int	i;

	putstr_fd(label, 1);
	putendl_fd(":", 1);
	putstr_fd("  path: ", 1);
	if (c->path)
		putendl_fd(c->path, 1);
	else
		putendl_fd("(null)", 1);
	putendl_fd("  argv:", 1);
	if (!c->argv)
	{
		putendl_fd("    (null)", 1);
		return ;
	}
	i = 0;
	while (c->argv[i] != NULL)
	{
		putstr_fd("    [", 1);
		putstr_fd(c->argv[i], 1);
		putendl_fd("]", 1);
		i++;
	}
}

// ------------- main: "cmd1" "cmd2" を受け取って検証 -------------
int	main(int argc, char **argv, char **envp)
{
	t_cmd	c1;
	t_cmd	c2;
	int		rc1;
	int		rc2;

	if (argc != 3)
	{
		putendl_fd("Usage: ./cmd_init_test \"cmd1\" \"cmd2\"", 2);
		return (EXIT_FAILURE);
	}
	rc1 = cmd_init(&c1, argv[1], envp);
	rc2 = cmd_init(&c2, argv[2], envp);
	putendl_fd("== cmd_init results ==", 1);
	putstr_fd("cmd1 rc = ", 1); putendl_fd(rc1 == 0 ? "0 (OK)" : "-1 (NG)", 1);
	putstr_fd("cmd2 rc = ", 1); putendl_fd(rc2 == 0 ? "0 (OK)" : "-1 (NG)", 1);
	putendl_fd("", 1);
	print_cmd("cmd1", &c1);
	print_cmd("cmd2", &c2);
	return ((rc2 == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
}
