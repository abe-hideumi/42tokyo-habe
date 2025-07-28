/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_number2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:45:40 by babe              #+#    #+#             */
/*   Updated: 2025/07/23 12:18:37 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_group(int );

void	assign_group(t_stack *a, int stack_size)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp->next != NULL)
	{
		tmp->group = ;
		tmp = tmp->next;
	}
}