/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:21:10 by habe              #+#    #+#             */
/*   Updated: 2025/09/22 12:04:32 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	close_and_perror(int pfd[2], const char *msg)
{
	close_safe(&pfd[0]);
	close_safe(&pfd[1]);
	if (msg != NULL)
		perror(msg);
}

static void	child_exec_in(t_px *px, t_cmd *c, int pfd[2], char *const envp[])
{
	if (px->fd_in >= 0)
	{
		if (dup2(px->fd_in, STDIN_FILENO) < 0)
		{
			perror("dup2 stdin");
			free_all(c, NULL);
			exit(1);
		}
	}
	else
	{
		int	null_fd = open("/dev/null", O_RDONLY);
		if (null_fd >= 0)
		{
			dup2(null_fd, STDIN_FILENO);
			close(null_fd);
		}
	}
	if (dup2(pfd[1], STDOUT_FILENO) < 0)
	{
		perror("dup2 stdout");
		free_all(c, NULL);
		exit(1);
	}
	close_and_perror(pfd, NULL);
	if (bad_command(c) != 0)
	{
		free_all(c, NULL);
		exit(127);
	}
	execve(c->path, c->argv, envp);
	perror("execve left");
	free_all(c, NULL);
	exit(126);
}

static void	child_exec_out(t_px *px, t_cmd *c, int pfd[2], char *const envp[])
{
	if (dup2(pfd[0], STDIN_FILENO) < 0)
	{
		perror("dup2 stdin");
		free_all(c, NULL);
		exit(1);
	}
	else
	{
		if (dup2(px->fd_out, STDOUT_FILENO) < 0)
		{
			perror("dup2 stdout");
			free_all(c, NULL);
			exit(1);
		}
	}
	close_and_perror(pfd, NULL);
	if (bad_command(c) != 0)
	{
		free_all(c, NULL);
		exit(127);
	}
	execve(c->path, c->argv, envp);
	perror("execve right");
	free_all(c, NULL);
	exit(126);
}

int	connect_pipe(t_px *px, t_cmd *c1, t_cmd *c2, char *const envp[])
{
	int		pfd[2];
	pid_t	p1;
	pid_t	p2;
	int		st1;
	int		st2;

	if (pipe(pfd) < 0)
		return (perror("pipe"), 1);
	p1 = fork();
	if (p1 < 0)
		return (close_and_perror(pfd, "fork"), 1);
	if (p1 == 0)
		child_exec_in(px, c1, pfd, envp);
	p2 = fork();
	if (p2 < 0)
		return (close_and_perror(pfd, "fork"), 1);
	if (p2 == 0)
		child_exec_out(px, c2, pfd, envp);
	else
	{
		st2 = 127;
	}
	close_and_perror(pfd, NULL);
	waitpid(p1, &st1, 0);
	waitpid(p2, &st2, 0);
	if (st2 != 0)
		return (127);
	else if (st2 == 0)
		return (0);
	return (1);
}
