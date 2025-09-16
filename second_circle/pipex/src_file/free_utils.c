/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:52:04 by habe              #+#    #+#             */
/*   Updated: 2025/09/16 12:23:57 by habe             ###   ########.fr       */
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
	free_split(c1->argv);
	free_split(c2->argv);
	if (c1->path != NULL)
		free(c1->path);
	if (c2->path != NULL)
		free(c2->path);
}
