/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:44:20 by habe              #+#    #+#             */
/*   Updated: 2025/07/28 13:55:55 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicate(t_stack *a)
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

static void	assign_order(t_stack *a)
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
		tmp -> order = count;
		tmp = tmp -> next;
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
	int		group_size;

	if (stack_size <= 0)
		return ;
	tmp = a->top;
	group_size = (stack_size + 5) / 6;
	while (tmp != NULL)
	{
		tmp->group = tmp->order / group_size;
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
	if (argc == 2)
		free_split(nbrs, i);
	check_duplicate(a);
	assign_order(a);
	assign_group(a, a->size);
}
