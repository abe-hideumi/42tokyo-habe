/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:44:20 by habe              #+#    #+#             */
/*   Updated: 2025/08/19 18:29:13 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicate(t_stack *a, t_stack *b, char **sp)
{
	t_node	*tmp;
	t_node	*checker;

	tmp = a->top;
	while (tmp != NULL)
	{
		checker = tmp->next;
		while (checker != NULL)
		{
			if (tmp->nbr == checker->nbr)
				error_exit(a, b, sp);
			checker = checker->next;
		}
		tmp = tmp->next;
	}
}

static void	assign_order(t_stack *a)
{
	int		o_count;
	t_node	*tmp;
	t_node	*checker;

	tmp = a->top;
	while (tmp != NULL)
	{
		o_count = 0;
		checker = a->top;
		while (checker != NULL)
		{
			if (tmp->nbr > checker->nbr)
				o_count++;
			checker = checker->next;
		}
		tmp->order = o_count;
		if (a->size - o_count <= 5)
			tmp->sign = 1;
		else
			tmp->sign = 0;
		tmp = tmp->next;
	}
}

static int	handle_group_size(int stack_size)
{
	if (stack_size >= 500)
		return (18);
	else if (stack_size >= 400)
		return (16);
	else if (stack_size >= 300)
		return (14);
	else if (stack_size >= 200)
		return (12);
	else if (stack_size >= 100)
		return (8);
	else
		return (6);
}

static int	assign_group(t_stack *a, int stack_size)
{
	t_node	*tmp;
	int		div_g;
	int		g_size;

	if (stack_size <= 0)
		return (0);
	div_g = handle_group_size(stack_size);
	g_size = (stack_size + div_g - 1) / div_g;
	tmp = a->top;
	while (tmp != NULL)
	{
		tmp->group = tmp->order / g_size;
		tmp = tmp->next;
	}
	return (div_g);
}

int	put_in_stack_a(t_stack *a, t_stack *b, char **nbrs, char **sp)
{
	t_node	*tmp;
	int		i;
	int		nbr;

	i = 0;
	while (nbrs[i] != NULL)
	{
		nbr = check_atoi(a, b, sp, nbrs[i]);
		tmp = node_new(nbr);
		if (tmp == NULL)
			error_exit(a, b, sp);
		node_add_back(&a->top, tmp);
		a->size++;
		i++;
	}
	check_duplicate(a, b, sp);
	assign_order(a);
	return (assign_group(a, a->size));
}
