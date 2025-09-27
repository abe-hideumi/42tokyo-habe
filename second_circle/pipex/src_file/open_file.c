/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:28:23 by habe              #+#    #+#             */
/*   Updated: 2025/09/27 23:13:24 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	open_infile(t_px *px, const char *path)
{
	int	fd;

	if (px == NULL || bad_command(px->c1) != 0)
	{
		px->fd_in = -1;
		return ;
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "pipex: ", 7);
		perror(px->infile);
		px->fd_in = -1;
		return ;
	}
	px->fd_in = fd;
}

int	open_outfile(t_px *px, char *path)
{
	char	*use;
	int		fd;

	if (px == NULL)
		return (perror("open outfile: px is NULL"), 1);
	if (path != NULL && path[0] != '\0')
		use = path;
	else
		use = "outfile";
	fd = open(use, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		px->fd_out = -1;
		write(2, "pipex: ", 7);
		return (perror(px->outfile), 1);
	}
	px->fd_out = fd;
	return (0);
}
