/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:44:20 by habe              #+#    #+#             */
/*   Updated: 2025/07/21 18:54:04 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(t_stack *a)
{
	t_node	*current;
	t_node	*checker;

	current = a->top;
	while (current)
	{
		checker = current -> next;
		while (checker)
		{
			if (current -> nbr == checker -> nbr)
				error_exit();
			checker = checker -> next;
		}
		current = current -> next;
	}
}

void	assign_order(t_stack *a)
{
	int		count;
	t_node	*current;
	t_node	*checker;

	current = a->top;
	while (current)
	{
		count = 0;
		checker = a->top;
		while (checker)
		{
			if (current -> nbr > checker -> nbr)
				count++;
			checker = checker -> next;
		}
		current -> nbr_size = count + 1;
		current = current -> next;
	}
}

static void	free_split(char **numbers, int count)
{
	while (--count >= 0)
		free(numbers[count]);
	free(numbers);
}

void	put_in_stack_a(t_stack *a, char **argv, int argc)
{
	t_node	*tmp;
	char	**numbers;
	int		i;

	if (argc == 2)
		numbers = ft_split(argv[0], ' ');
	else
		numbers = argv;
	i = 0;
	while (numbers[i] != NULL)
	{
		tmp = node_new(check_atoi(numbers[i]));
		node_add_back(&a->top, tmp);
		a->size++;
		i++;
	}
	if (argc == 2)
		free_split(numbers, i);
}
