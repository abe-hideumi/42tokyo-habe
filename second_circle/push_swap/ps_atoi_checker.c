/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:47:44 by habe              #+#    #+#             */
/*   Updated: 2025/08/19 13:24:21 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sign_null_check(const char *str, int	*sign)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	if (str[i] == '\0' || str[i] == '-' || str[i] == '+')
		return (-1);
	return (i);
}

static int	nbr_check(char c)
{
	if (c < '0' || c > '9')
		return (-1);
	return (0);
}

static int	int_max_min_check(int sign, long long nbr)
{
	if ((sign == 1 && nbr > INT_MAX)
		|| (sign == -1 && (nbr * -1) < INT_MIN))
		return (-1);
	return (0);
}

int	check_atoi(t_stack *a, t_stack *b, char **sp, const char *str)
{
	int			i;
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	if (str == NULL || str[0] == '\0')
		error_exit(a, b, sp);
	i = sign_null_check(str, &sign);
	if (i < 0)
		error_exit(a, b, sp);
	while (str[i] != '\0')
	{
		if (nbr_check(str[i]) != 0)
			error_exit(a, b, sp);
		result = result * 10 + (str[i] - '0');
		if (int_max_min_check(sign, result) != 0)
			error_exit(a, b, sp);
		i++;
	}
	return ((int)(sign * result));
}
