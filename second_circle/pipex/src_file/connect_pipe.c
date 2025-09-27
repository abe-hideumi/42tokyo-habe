/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:18:49 by babe              #+#    #+#             */
/*   Updated: 2025/09/27 23:40:24 by babe             ###   ########.fr       */
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

static void	child_assist(t_px *px)
{
	if (px->fd_in < 0)
	{
		free_all(px);
		exit(1);
	}
	if (dup2(px->fd_in, STDIN_FILENO) < 0)
	{
		free_all(px);
		exit(1);
	}
}

static void	child_exec_in(t_px *px, int pfd[2], char *const envp[])
{
	child_assist(px);
	close_safe(&px->fd_in);
	if (dup2(pfd[1], STDOUT_FILENO) < 0)
	{
		free_all(px);
		exit(1);
	}
	close_and_perror(pfd, NULL);
	if (bad_command(px->c1) != 0)
	{
		free_all(px);
		exit(127);
	}
	execve(px->c1->path, px->c1->argv, envp);
	perror("execve left");
	free_all(px);
	exit(126);
}

static void	child_exec_out(t_px *px, int pfd[2], char *const envp[])
{
	if (dup2(pfd[0], STDIN_FILENO) < 0)
	{
		perror("dup2 stdin");
		free_all(px);
		exit(1);
	}
	if (px->fd_out < 0 || dup2(px->fd_out, STDOUT_FILENO) < 0)
	{
		free_all(px);
		exit(1);
	}
	close_safe(&px->fd_out);
	close_and_perror(pfd, NULL);
	if (bad_command(px->c2) != 0)
	{
		free_all(px);
		exit(127);
	}
	execve(px->c2->path, px->c2->argv, envp);
	perror("execve right");
	free_all(px);
	exit(126);
}

int	connect_pipe(t_px *px, char *const envp[])
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
		child_exec_in(px, pfd, envp);
	p2 = fork();
	if (p2 < 0)
		return (close_and_perror(pfd, "fork"), 1);
	if (p2 == 0)
		child_exec_out(px, pfd, envp);
	close_and_perror(pfd, NULL);
	waitpid(p1, &st1, 0);
	waitpid(p2, &st2, 0);
	if (st2 == 0)
		return (0);
	return (1);
}
