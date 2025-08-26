/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:59:24 by habe              #+#    #+#             */
/*   Updated: 2025/08/26 16:57:20 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_group(t_stack *a, int g1, int g2)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp != NULL)
	{
		if ((tmp->group == g1 || tmp->group == g2) && tmp->sign != 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	need_reverse(t_stack *a, int g1, int g2)
{
	t_node	*tmp;
	int		pos1;
	int		pos2;
	int		count;

	if (a->top == NULL)
		return (0);
	tmp = a->top;
	pos1 = 0;
	pos2 = 0;
	count = 0;
	while (tmp != NULL)
	{
		if ((tmp->group == g1 || tmp->group == g2)
			&& pos1 == 0 && tmp->sign != 1)
			pos1 = count;
		if ((tmp->group == g1 || tmp->group == g2) && tmp->sign != 1)
			pos2 = count;
		count++;
		tmp = tmp->next;
	}
	if (pos1 > ((int)a->size - pos2))
		return (pos2);
	return (pos1);
}

static void	rr_rrr_handle(t_stack *a, t_stack *b, int g1, int g2)
{
	int	pos;

	pos = need_reverse(a, g1, g2);
	if (pos > ((int)a->size / 2))
	{
		pos = (int)a->size - pos;
		while (pos-- > 0)
			rra(a);
	}
	else
	{
		while (pos-- > 0)
		{
			if (b->top != NULL && b->top->group == g1)
				rr(a, b);
			else
				ra(a);
		}
	}
}

static void	sort_b_stack(t_stack *a, t_stack *b, int g1, int g2)
{
	if (b->top == NULL || b->top->next == NULL)
		return ;
	if (b->top->group == g1)
	{
		if (a->top->group != g1 && a->top->group != g2)
			rr(a, b);
		else
			rb(b);
	}
}

void	push_to_b(t_stack *a, t_stack *b, int max_g)
{
	int	g1;
	int	pair;

	g1 = max_g / 2;
	pair = 1;
	while (pair <= max_g)
	{
		while (has_group(a, g1, g1 + pair) != 0)
		{
			if ((a->top->group == g1 || a->top->group == g1 + pair)
				&& a->top->sign != 1)
			{
				pb(a, b);
				sort_b_stack(a, b, g1, g1 + pair);
			}
			else
				rr_rrr_handle(a, b, g1, g1 + pair);
		}
		g1--;
		pair += 2;
	}
	small_sort(a, b);
}
