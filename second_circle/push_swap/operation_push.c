/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:24:31 by habe              #+#    #+#             */
/*   Updated: 2025/07/21 15:50:52 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (b == NULL || b->top == NULL)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	tmp->next = a->top;
	a->top = tmp;
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (a == NULL || a->top == NULL)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	tmp->next = b->top;
	b->top = tmp;
	ft_printf("pb\n");
}
