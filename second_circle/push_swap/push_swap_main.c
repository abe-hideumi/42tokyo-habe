/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:36:08 by habe              #+#    #+#             */
/*   Updated: 2025/07/28 15:03:47 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	stack_initial(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	a->size = 0;
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
		return (0);
	stack_initial(&a, &b);
	put_in_stack_a(&a, &argv[1], argc);
	push_to_b(&a, &b);

	return (0);
}


// static void	print_stack(const char *name, t_stack *stack)
// {
// 	t_node	*tmp;

// 	tmp = stack->top;
// 	ft_printf("stack %s: ", name);
// 	while (tmp)
// 	{
// 		ft_printf("%d ", tmp->nbr);
// 		tmp = tmp->next;
// 	}
// 	ft_printf("\n");
// }
