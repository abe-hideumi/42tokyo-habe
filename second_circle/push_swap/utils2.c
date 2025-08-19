/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:54:13 by habe              #+#    #+#             */
/*   Updated: 2025/08/19 13:58:03 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *lst)
{
	t_node	*tmp;
	t_node	*next;

	if (lst == NULL || lst->top == NULL)
		return ;
	tmp = lst->top;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	lst->top = NULL;
	lst->size = 0;
}

void	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

void	free_split(char **sp)
{
	int	i;

	if (sp == NULL)
		return ;
	i = 0;
	while (sp[i] != NULL)
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

void	error_exit(t_stack *a, t_stack *b, char **sp)
{
	free_all(a, b);
	free_split(sp);
	write(2, "Error\n", 6);
	exit (1);
}
