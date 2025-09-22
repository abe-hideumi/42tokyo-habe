/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:52:04 by habe              #+#    #+#             */
/*   Updated: 2025/09/22 10:25:19 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
	free(sp);
}

void	free_all(t_cmd *c1, t_cmd *c2)
{
	if (c1 != NULL)
	{
		free_split(c1->argv);
		if (c1->path != NULL)
			free(c1->path);
		c1->argv = NULL;
		c1->path = NULL;
	}
	if (c2 != NULL)
	{
		free_split(c2->argv);
		if (c2->path != NULL)
			free(c2->path);
		c2->argv = NULL;
		c2->path = NULL;
	}
}
