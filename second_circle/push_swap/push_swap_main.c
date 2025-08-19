/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:42:35 by habe              #+#    #+#             */
/*   Updated: 2025/08/19 12:43:42 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	stack_init(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}

static int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (a == NULL || a->top == NULL)
		return (1);
	cur = a->top;
	while (cur->next != NULL)
	{
		if (cur->order > cur->next->order)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	**split;
	char	**nbrs;
	int		groups;

	if (argc <= 1)
		return (0);
	stack_init(&a, &b);
	split = NULL;
	if (argc == 2)
		handle_split(&nbrs, &split, argv[1]);
	else
		nbrs = &argv[1];
	groups = put_in_stack_a(&a, &b, nbrs, split);
	if (split != NULL)
		free_split(split);
	groups = put_in_stack_a(&a, &b, &argv[1], argc);
	if (a.size <= 5 && is_sorted(&a) == 0)
		small_sort(&a, &b);
	else if (a.size > 5 && is_sorted(&a) == 0)
	{
		push_to_b(&a, &b, groups - 1);
		push_to_a(&a, &b);
	}
	free_all(&a, &b);
	return (0);
}
