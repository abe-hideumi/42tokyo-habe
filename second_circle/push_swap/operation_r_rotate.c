/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:51:47 by habe              #+#    #+#             */
/*   Updated: 2025/07/21 17:48:36 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(t_stack *lst)
{
	t_node	*last;
	t_node	*prev;

	if (lst == NULL || lst->top == NULL || lst->top->next == NULL)
		return ;
	last = node_last(lst->top);
	prev = lst->top;
	while (prev->next != last)
		prev = prev->next;
	prev->next = NULL;
	last->next = lst->top;
	lst->top = last;
}

void	rra(t_stack *a)
{
	r_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	r_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	r_rotate(a);
	r_rotate(b);
	ft_printf("rrr\n");
}
