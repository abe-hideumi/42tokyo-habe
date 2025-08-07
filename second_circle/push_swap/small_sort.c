/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:54:40 by habe              #+#    #+#             */
/*   Updated: 2025/08/06 14:30:25 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	element_3(t_stack *a)
{
	int		s1;
	int		s2;
	int		s3;

	s1 = a->top->order;
	s2 = a->top->next->order;
	s3 = a->top->next->next->order;
	if (s1 > s2 && s1 > s3)
		ra(a);
	else if (s2 > s1 && s2 > s3)
		rra(a);
	s1 = a->top->order;
	s2 = a->top->next->order;
	if (s1 > s2)
		sa(a);
}

static int	find_min_pos(t_stack *a)
{
	t_node	*tmp;
	int		min;
	int		pos;
	int		i;

	tmp = a->top;
	min = tmp->order;
	pos = 0;
	i = 0;
	while (tmp != NULL)
	{
		if (min > tmp->order)
		{
			min = tmp->order;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static void	element_5(t_stack *a, t_stack *b)
{
	int	pos;
	int	pa_c;

	pa_c = 0;
	while (a->size > 3)
	{
		pos = find_min_pos(a);
		if (pos <= a->size / 2)
			while (pos-- > 0)
				ra(a);
		else
			while (pos++ < a->size)
				rra(a);
		pb(a, b);
		pa_c++;
	}
	element_3(a);
	while (pa_c-- > 0)
		pa(a, b);
}

void	small_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2 && a->top->order > a->top->next->order)
		sa(a);
	else if (a->size == 3)
		element_3(a);
	else if (a->size <= 5)
		element_5(a, b);
}
