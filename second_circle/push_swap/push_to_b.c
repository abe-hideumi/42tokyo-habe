/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:59:24 by habe              #+#    #+#             */
/*   Updated: 2025/07/28 18:14:23 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_group(t_stack *a, int group)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp != NULL)
	{
		if (tmp->group == group)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	need_reverse(t_stack *lst, int group)
{
	t_node	*tmp;
	int		pos;

	tmp = lst->top;
	pos = 0;
	while (tmp != NULL)
	{
		pos++;
		if (tmp->group == group)
			break ;
		tmp = tmp->next;
	}
	if (lst->size / 2 < pos)
		return (1);
	return (0);
}

void	push_to_b(t_stack *a, t_stack *b)
{
	int	group;

	group = 0;
	while (group <= 4)
	{
		while (has_group(a, group) != 0)
		{
			if (a->top->group == group)
				pb(a, b);
			else if (need_reverse(a, group) != 0)
				rra(a);
			else
				ra(a);
		}
		group++;
	}
}
