/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:09:48 by habe              #+#    #+#             */
/*   Updated: 2025/08/11 12:41:14 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_max_and_pos(t_stack *b, int *max_order, int *pos)
{
	t_node	*tmp;
	int		i;

	if (b->top == NULL)
		return ;
	tmp = b->top;
	*max_order = tmp->order;
	*pos = 0;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->order > *max_order)
		{
			*max_order = tmp->order;
			*pos = i;
		}
		tmp = tmp->next;
		i++;
	}
}

static void	sort_a_stack(t_stack *a, t_stack *b)
{
	if (a->top == NULL || a->top->next == NULL)
		return ;
	if ((b->top != NULL && b->top->next != NULL)
		&& (a->top->order > a->top->next->order)
		&& (b->top->order < b->top->next->order))
		ss(a, b);
	else if (a->top->order > a->top->next->order)
		sa(a);
}

void	push_to_a(t_stack *a, t_stack *b)
{
	int		pos;
	int		max_order;

	while (b->size != 0)
	{
		find_max_and_pos(b, &max_order, &pos);
		if (pos < b->size / 2)
			while (b->top->order != max_order && b->top->order != max_order - 1)
				rb(b);
		else
			while (b->top->order != max_order && b->top->order != max_order - 1)
				rrb(b);
		pa(a, b);
		sort_a_stack(a, b);
	}
}
