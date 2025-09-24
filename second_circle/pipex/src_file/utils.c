/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:28:43 by habe              #+#    #+#             */
/*   Updated: 2025/09/24 13:24:26 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	has_slash(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	usage_print_exit(void)
{
	write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 38);
	exit(1);
}

void	cmd_not_print(t_cmd *cmd)
{
	int	i;

	i = 0;
	ft_printf("pipex: ");
	while (cmd->argv[i] != NULL)
	{
		write(2, cmd->argv[i], ft_strlen(cmd->argv[i]));
		i++;
	}
	write(2, ": command not found\n", 20);
}

int	bad_command(t_cmd *c)
{
	if (c == NULL)
		return (1);
	if (c->path == NULL)
		return (1);
	if (c->argv == NULL)
		return (1);
	if (c->argv[0] == NULL)
		return (1);
	if (c->argv[0][0] == '\0')
		return (1);
	return (0);
}

void	close_safe(int *fd)
{
	if (fd != NULL && *fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
}
