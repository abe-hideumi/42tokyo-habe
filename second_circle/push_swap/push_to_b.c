/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:59:24 by habe              #+#    #+#             */
/*   Updated: 2025/07/29 18:58:51 by habe             ###   ########.fr       */
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
		if (tmp->group == group)
			break ;
		pos++;
		tmp = tmp->next;
	}
	if (pos >= lst->size / 2)
		return (1);
	return (0);
}

static void	sort_b_stack(t_stack *b)
{
	if (b->top && b->top->next
		&& b->top->nbr < b->top->next->nbr)
		sb(b);
}

void	push_to_b(t_stack *a, t_stack *b)
{
	int	group;
	int	group_count;

	if (a->size > 100)
		group_count = 10;
	else
		group_count = 5;
	group = 0;
	while (group <= group_count)
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
