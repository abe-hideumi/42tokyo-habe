/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:59:24 by habe              #+#    #+#             */
/*   Updated: 2025/08/05 17:04:28 by habe             ###   ########.fr       */
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

static int	need_reverse(t_stack *a, int group)
{
	t_node	*tmp;
	int		pos;

	if (a->top == NULL)
		return (0);
	tmp = a->top;
	pos = 0;
	while (tmp != NULL)
	{
		if (tmp->group == group)
			break ;
		pos++;
		tmp = tmp->next;
	}
	if (pos >= a->size / 2)
		return (1);
	return (0);
}

static void	sort_b_stack(t_stack *b)
{
	if ((b->top && b->top->next) \
		&& b->top->order < b->top->next->order)
		sb(b);
}

void	push_to_b(t_stack *a, t_stack *b)
{
	int	group;
	int	max_g;

	if (a->size >= 100)
		max_g = 9;
	else
		max_g = 4;
	group = 0;
	while (group <= max_g)
	{
		while (has_group(a, group) != 0)
		{
			if (a->top->group == group)
			{
				pb(a, b);
				sort_b_stack(b);
			}
			else if (need_reverse(a, group) != 0)
				rra(a);
			else
				ra(a);
		}
		group++;
	}
}
