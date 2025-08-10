/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:17:36 by habe              #+#    #+#             */
/*   Updated: 2025/08/10 14:56:35 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

t_node	*node_new(int nbr)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		error_exit();
	node->nbr = nbr;
	node->order = 0;
	node->group = 0;
	node->sign = 0;
	node->next = NULL;
	return (node);
}

void	node_add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = node_last(*lst);
	last->next = new;
}

t_node	*node_last(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	is_sorted(t_stack *a)
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
