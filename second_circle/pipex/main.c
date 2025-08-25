/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:48:20 by habe              #+#    #+#             */
/*   Updated: 2025/08/25 18:41:21 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **sp)
{
	int	i;

	if (sp == NULL)
		return ;
	i = 0;
	while (sp[i] != NULL)
	{
		free(sp[i]);
		i++;
	}
	free(sp[i]);
}

int	cmd_init(t_cmd *dest, const char *argv)
{
	dest->cmd = ft_split(argv, ' ');
	dest->path = NULL;
	if (dest->cmd == NULL || dest == NULL)
		return (-1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cmd	cmd1;
	t_cmd	cmd2;

	if (argc != 5)
		return (0);
	cmd1.cmd = ft_split(argv[2], ' ');
	cmd2.cmd = ft_split(argv[3], ' ');


	return (0);
}
