/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap _main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:36:08 by habe              #+#    #+#             */
/*   Updated: 2025/07/15 13:55:17 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(t_node *a)
{
	t_node	*current;
	t_node	*checker;

	current = a;
	while (current)
	{
		checker = current -> next;
		while (checker)
		{
			if (current -> nbr == checker -> nbr)
			{
				write(2, "Error\n", 6);
				exit (1);
			}
			checker = checker -> next;
		}
		current = current -> next;
	}
}

void	assign_order(t_node *a)
{
	int		count;
	t_node	*current;
	t_node	*checker;

	current = a;
	while (current)
	{
		count = 0;
		checker = a;
		while (checker)
		{
			if (current -> nbr > checker -> nbr)
				count++;
			checker = checker -> next;
		}
		current -> nbr_size = count + 1;
		current = current -> next;
	}
	return ;
}

int	check_atoi(char *str, int *dst)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str == NULL || str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > 2147483647) || (sign == -1 && -result < -2147483648))
			return (0);
		i++;
	}
	return (1);
}

void	put_in_number(t_node *a, char **src)
{
	int	i;

	i = 0;
	while (src[i] != NULL)
	{
		if (src_number_check(src[i]) != 0)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		a -> nbr = ft_atoi(src[i]);
		if (a -> nbr == 0 && src[i][0] != '0')
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
	put_in_number(a, &argv[1]);
	check_duplicate(a);
	assign_order(a);
	return (0);
}
