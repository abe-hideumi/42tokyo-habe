/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:36:08 by habe              #+#    #+#             */
/*   Updated: 2025/08/13 17:50:13 by babe             ###   ########.fr       */
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
		handle_split(&nbrs, &split, argv[1])
	else
		nbrs = &argv[1];
	groups = put_in_stack_a(&a, &b, nbrs, split);
	if (split != NULL)
		free_split(split);
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
