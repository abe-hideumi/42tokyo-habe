/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:59:24 by habe              #+#    #+#             */
/*   Updated: 2025/08/05 19:03:49 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_group(t_stack *a, int group)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp != NULL)
	{
		if (tmp->group == group && tmp->sign != 1)
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

static void	sort_b_stack(t_stack *a, t_stack *b)
{
	if (b->top || b->top->next)
		return ;
	if ((b->top->order < b->top->next->order) \
		&& (a->top != NULL && a->top->next != NULL) \
		&& (a->top->order > a->top->next->order))
		ss(a, b);
	if (b->top->order < b->top->next->order)
		sb(b);
}

void	push_to_b(t_stack *a, t_stack *b)
{
	int	group;
	int	max_g;
	int	pair;

	if (a->size >= 100)
		max_g = 9;
	else
		max_g = 5;
	group = max_g / 2;
	pair = 1;
	while (pair <= max_g)
	{
		while (has_group(a, group) != 0)
		{
			if ((a->top->group == group || a->top->group == group + pair) \
				&& a->top->sign != 1)
			{
				pb(a, b);
				sort_b_stack(a, b);
			}
			else if (need_reverse(a, group) != 0)
				rra(a);
			else
				ra(a);
		}
		group--;
		pair += 2;
	}
	small_sort(a, b);
}
