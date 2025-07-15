/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap _main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:36:08 by habe              #+#    #+#             */
/*   Updated: 2025/07/14 18:40:14 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_check(t_node *a)
{
	int		count;
	int		tmp;
	t_node	*start;
	
	count = 0;
	tmp = a -> nbr;
	start = a;
	while (!a)
	{
		while (!a)
		{
			if (tmp >= a -> nbr)
				count++;
			a = a -> next;
		}
		a -> nbr_size = count;
		a -> next = start;
		count = 0; 
	}
	return (0);
}

int	src_number_check(char *src)
{
	int	i;

	i = 0;
	if (src[i] == '+' || src[i] == '-')
		i++;
	if (src[i] == '\0')
		return (1);
	while (src[i] != '\0')
	{
		if (src[i] < '0' || src[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	put_in_number(t_node *a, char **src)
{
	int	i;
	
	i = 0;
	while (src[i] != '\0')
	{
		if (src_number_check(src[i]) != 0)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		a -> nbr = ft_atoi(src[i]);
		if (a -> nbr == 0 && src[i] != '0')
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		a = a -> next;
		i++;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	
	if (argc <= 1)
		return (0);
	a = malloc(sizeof (t_node) * argc - 1);
	put_in_number(a, argv[1]);
	order_check(a);
	return (0);
}
