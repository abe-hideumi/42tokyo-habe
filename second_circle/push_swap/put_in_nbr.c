/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:44:20 by habe              #+#    #+#             */
/*   Updated: 2025/08/05 18:56:09 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicate(t_stack *a)
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
				error_exit();
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
		tmp = tmp->next;
	}
}

static void	free_split(char **nbrs, int count)
{
	while (--count >= 0)
		free(nbrs[count]);
	free(nbrs);
}

static void	assign_group(t_stack *a, int stack_size)
{
	t_node	*tmp;
	int		div_g;
	int		g_size;

	if (stack_size <= 0)
		return ;
	if (stack_size >= 100)
		div_g = 10;
	else
		div_g = 6;
	g_size = (stack_size + div_g - 1) / div_g;
	tmp = a->top;
	while (tmp != NULL)
	{
		tmp->group = tmp->order / g_size;
		tmp = tmp->next;
	}
}

void	put_in_stack_a(t_stack *a, char **argv, int argc)
{
	t_node	*tmp;
	char	**nbrs;
	int		i;

	if (argc == 2)
		nbrs = ft_split(argv[0], ' ');
	else
		nbrs = argv;
	i = 0;
	while (nbrs[i] != NULL)
	{
		tmp = node_new(check_atoi(nbrs[i]));
		node_add_back(&a->top, tmp);
		a->size++;
		i++;
	}
	if (nbrs != argv)
		free_split(nbrs, i);
	check_duplicate(a);
	assign_order(a);
	assign_group(a, a->size);
}
