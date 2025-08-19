/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:42:35 by habe              #+#    #+#             */
/*   Updated: 2025/08/19 13:06:38 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	stack_init(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}

static int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (a == NULL || a->top == NULL)
		return (0);
	cur = a->top;
	while (cur->next != NULL)
	{
		if (cur->order > cur->next->order)
			return (1);
		cur = cur->next;
	}
	return (0);
}

static char	**prepare_nbrs(int argc, char **argv, char **split)
{
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		return (split);
	}
	return (&argv[1]);
}

static void	sort_handle(t_stack *a, t_stack *b, int groups)
{
	if (is_sorted(a) == 0)
		return ;
	if (a->size <= 5)
		small_sort(a, b);
	else
	{
		push_to_b(a, b, groups - 1);
		push_to_a(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	**split;
	char	**nbrs;
	int		groups;

	if (argc <= 1)
		return (0);
	stack_init(&a, &b);
	split = NULL;
	nbrs = prepare_nbrs(argc, argv, split);
	if (argc == 2 && nbrs == NULL)
		error_exit(&a, &b, NULL);
	groups = put_in_stack_a(&a, &b, nbrs, split);
	if (split != NULL)
		free_split(split);
	sort_handle(&a, &b, groups);
	free_all(&a, &b);
	return (0);
}
