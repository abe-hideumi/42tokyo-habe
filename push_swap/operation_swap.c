/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:24:28 by habe              #+#    #+#             */
/*   Updated: 2025/07/08 14:14:40 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	printf("topのアドレス: %p\n", (void *)a->top);
	if (!a && !a -> top && !a -> top -> next)
	{
		first = a -> top;
		second = a -> top -> next;
		first -> next = second -> next;
		second -> next = first;
		a -> top = second;
		printf("topのアドレス（変更後）: %p\n", (void *)a->top);
	}
	return ;
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b && !b -> top && !b -> top -> next)
	{
		first = b -> top;
		second = b -> top -> next;
		first -> next = second -> next;
		second -> next = first;
		b -> top = second;
	}
	return ;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	return ;
}
