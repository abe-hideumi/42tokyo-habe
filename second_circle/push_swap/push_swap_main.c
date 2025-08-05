/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:36:08 by habe              #+#    #+#             */
/*   Updated: 2025/08/05 17:23:19 by habe             ###   ########.fr       */
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

	if (argc <= 1)
		return (0);
	stack_init(&a, &b);
	put_in_stack_a(&a, &argv[1], argc);
	if (a.size <= 5)
		small_sort(&a, &b);
	else
	{
		push_to_b(&a, &b);
		push_to_a(&a, &b);
	}
	return (0);
}

// print_stack("a", &a);
// print_stack("b", &b);

// static void	print_stack(const char *name, t_stack *stack)
// {
// 	t_node	*tmp;

// 	tmp = stack->top;
// 	ft_printf("%s: ", name);
// 	while (tmp)
// 	{
// 		ft_printf("(%d) ", tmp->order);
// 		tmp = tmp->next;
// 	}
// 	ft_printf("\n");
// }

//(%d) , tmp->group = (group_nbr),
//%d   , tmp->nbr = nbr,
//(%d) , tmp->order = (order),
