/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:36:08 by habe              #+#    #+#             */
/*   Updated: 2025/08/06 15:26:38 by babe             ###   ########.fr       */
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
	int		div_g;

	if (argc <= 1)
		return (0);
	stack_init(&a, &b);
	div_g = put_in_stack_a(&a, &argv[1], argc);
	if (a.size <= 5)
		small_sort(&a, &b);
	else
	{
		push_to_b(&a, &b, div_g - 1);
		push_to_a(&a, &b);
	}
	return (0);
}
