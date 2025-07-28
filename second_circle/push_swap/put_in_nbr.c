/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:44:20 by habe              #+#    #+#             */
/*   Updated: 2025/07/23 11:46:32 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(t_stack *a)
{
	t_node	*tmp;
	t_node	*checker;

	tmp = a->top;
	while (tmp)
	{
		checker = tmp -> next;
		while (checker)
		{
			if (tmp -> nbr == checker -> nbr)
				error_exit();
			checker = checker -> next;
		}
		tmp = tmp -> next;
	}
}

void	assign_order(t_stack *a)
{
	int		count;
	t_node	*tmp;
	t_node	*checker;

	tmp = a->top;
	while (tmp)
	{
		count = 0;
		checker = a->top;
		while (checker)
		{
			if (tmp -> nbr > checker -> nbr)
				count++;
			checker = checker -> next;
		}
		tmp -> nbr_size = count + 1;
		tmp = tmp -> next;
	}
}

static void	free_split(char **nbrs, int count)
{
	while (--count >= 0)
		free(nbrs[count]);
	free(nbrs);
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
	if (argc == 2)
		free_split(nbrs, i);
	check_duplicate(&a);
	assign_order(&a);
	if (a->size >= 6)
		assign_group(&a, a->size);
}
