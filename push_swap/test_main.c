/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:58:09 by habe              #+#    #+#             */
/*   Updated: 2025/07/08 14:15:19 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	push_front(t_stack *stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	new->next = stack->top;
	stack->top = new;
}

void	print_stack(t_stack *stack, char *name)
{
	t_node	*cur;

	printf("%s: (top = %p): ", name, (void *)stack->top);
	cur = stack->top;
	while (cur)
	{
		printf("%d ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	a;
	t_stack	b;

	a.top = NULL;
	b.top = NULL;

	push_front(&a, 5);
	push_front(&a, 3);
	push_front(&a, 1);

	push_front(&b, 8);
	push_front(&b, 7);
	push_front(&b, 6);

	print_stack(&a, "a");
	print_stack(&b, "b");

	sa(&a);
	print_stack(&a, "a after sa");

	sb(&b);
	print_stack(&b, "b after sb");

	ss(&a, &b);
	print_stack(&a, "a after ss");
	print_stack(&b, "b after ss");

	return (0);
}
