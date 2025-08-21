/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:42:35 by habe              #+#    #+#             */
/*   Updated: 2025/08/21 17:49:21 by babe             ###   ########.fr       */
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

static int	prepare_nbrs(int argc, char **argv, char ***nbrs)
{
	if (argc == 2)
	{
		*nbrs = ft_split(argv[1], ' ');
		if (*nbrs == NULL)
			return (0);
		return (1);
	}
	*nbrs = &argv[1];
	return (0);
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
	char	**nbrs;
	int		sp;
	int		groups;

	if (argc <= 1)
		return (0);
	stack_init(&a, &b);
	nbrs = NULL;
	sp = prepare_nbrs(argc, argv, &nbrs);
	if ((argc == 2 && sp == 0) || nbrs == NULL)
		error_exit(&a, &b, NULL);
	groups = put_in_stack_a(&a, &b, nbrs, sp);
	if (argc == 2 && sp == 1)
		free_split(nbrs);
	sort_handle(&a, &b, groups);
	free_all(&a, &b);
	return (0);
}
