/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:54:13 by habe              #+#    #+#             */
/*   Updated: 2025/08/13 16:45:01 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *a, t_stack *b, char **sp)
{
	write(2, "Error\n", 6);
	free_all(a, b);
	if (sp != NULL)
		free_split(sp);
	exit (1);
}

static void	free_stack(t_stack *lst)
{
	t_node	*tmp;
	t_node	*next;

	tmp = lst->top;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	lst->top = NULL;
	lst->size = 0;
}

void	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

void	free_split(char **nbrs)
{
	int	i;

	i = 0;
	while (nbrs[i] != NULL)
		free(nbrs[i]);
	free(nbrs);
}
