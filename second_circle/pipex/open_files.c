/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:28:23 by habe              #+#    #+#             */
/*   Updated: 2025/09/14 15:42:32 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_safe(int *fd)
{
	if (fd && *fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
}

int	open_infile(t_px *px, const char *path)
{
	int	fd;

	fd = -1;
	if (path == NULL || path[0] == '\0' || px == NULL)
		return (perror("open infile: invalid path"), 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror("open infile"), 1);
	px->fd_in = fd;
	return (0);
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
		return (perror("open outfile"), 1);
	px->fd_out = fd;
	px->out_path = use;
	return (0);
}
