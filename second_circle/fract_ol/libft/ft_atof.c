/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:27:04 by habe              #+#    #+#             */
/*   Updated: 2025/10/01 16:34:53 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	decimal_analysis(const char *nptr)
{
	double	result;
	int		div;
	int		i;

	result = 0.0;
	div = 10;
	i = 0;
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]) != 0)
	{
		result = result + (double)(nptr[i] - '0') / div;
		div = div * 10;
		i++;
	}
	return (result);
}

double	ft_atof(const char *nptr)
{
	double	result;
	double	sign;
	int		i;

	result = 0.0;
	sign = 1.0;
	i = 0;
	while (ft_isspace(nptr[i]) != 0)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1.0;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] != '.' && ft_isdigit(nptr[i]) != 0)
	{
		result = result * 10.0 + (double)(nptr[i] - '0');
		i++;
	}
	if (nptr[i] == '.')
		result = result + decimal_analysis(&nptr[i + 1]);
	return (sign * result);
}

// int	main(int ac, char **av)
// {
// 	double	test;
	
// 	test = ft_atof(av[1]);
// 	printf("test = %f\n", test);
// 	test = atof(av[1]);
// 	printf("test = %f\n", test);
// 	return (0);
// }