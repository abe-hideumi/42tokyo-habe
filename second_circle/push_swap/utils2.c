/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:54:13 by habe              #+#    #+#             */
/*   Updated: 2025/08/10 14:56:45 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_split(char **nbrs, int count)
{
	while (--count >= 0)
		free(nbrs[count]);
	free(nbrs);
}
