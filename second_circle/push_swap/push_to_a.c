/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:09:48 by habe              #+#    #+#             */
/*   Updated: 2025/08/05 16:24:59 by habe             ###   ########.fr       */
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

void	push_to_a(t_stack *a, t_stack *b)
{
	int		pos;
	int		max_order;

	while (b->size != 0)
	{
		find_max_and_pos(b, &max_order, &pos);
		if (pos < b->size / 2)
			while (b->top->order != max_order)
				rb(b);
		else
			while (b->top->order != max_order)
				rrb(b);
		pa(a, b);
	}
}
