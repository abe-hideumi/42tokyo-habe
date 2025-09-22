/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:48:20 by habe              #+#    #+#             */
/*   Updated: 2025/09/22 13:51:14 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	close_files(t_px *px)
{
	close_safe(&px->fd_in);
	close_safe(&px->fd_out);
}

static int	cmd_all_set(t_px *px, char **cmd, char *const envp[])
{
	if (cmd_init(px->c1, cmd[0], envp) != 0)
		return (1);
	if (cmd_init(px->c2, cmd[1], envp) != 0)
	{
		free_all(px->c1, NULL);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_px	px;

	ft_memset(&px.c1, 0, sizeof(t_cmd));
	ft_memset(&px.c2, 0, sizeof(t_cmd));
	px.fd_in = -1;
	px.fd_out = -1;
	if (argc != 5)
		usage_print_exit();
	if (cmd_all_set(&px, &argv[2], envp) != 0)
		return (1);
	open_infile(&px, argv[1]);
	px.end_st = open_outfile(&px, argv[4]);
	if (px.end_st == 0)
		px.end_st = connect_pipe(&px, envp);
	else
		connect_pipe(&px, envp);
	if (px.end_st == 1 && px.c2->path == NULL)
		px.end_st = 127;
	close_files(&px);
	free_all(px.c1, px.c2);
	return (px.end_st);
}
