/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:47:44 by habe              #+#    #+#             */
/*   Updated: 2025/08/05 15:23:13 by habe             ###   ########.fr       */
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
		error_exit();
	return (i);
}

static void	fraud_check(char c)
{
	if (c < '0' || c > '9')
		error_exit();
}

static void	int_max_min_check(int sign, long long nbr)
{
	if ((sign == 1 && nbr > INT_MAX)
		|| (sign == -1 && (nbr * -1) < INT_MIN))
		error_exit();
}

int	check_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	if (str == NULL || str[0] == '\0')
		error_exit();
	i = sign_null_check(str, &sign);
	while (str[i] != '\0')
	{
		fraud_check(str[i]);
		result = result * 10 + (str[i] - '0');
		int_max_min_check(sign, result);
		i++;
	}
	return ((int)(sign * result));
}
