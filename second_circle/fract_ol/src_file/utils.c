/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:58:25 by habe              #+#    #+#             */
/*   Updated: 2025/10/05 14:45:05 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	param_check(const char *nptr)
{
	int	i;
	int	dot_count;

	if (nptr == NULL || nptr[0] == '\0')
		return (1);
	i = 0;
	dot_count = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	if (nptr[i] == '\0' || nptr[i] == '+' || nptr[i] == '-')
		return (1);
	while (nptr[i] != '\0')
	{
		if (nptr[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (1);
		}
		else if (ft_isdigit(nptr[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	usage_print(int msg)
{
	if (msg == 0)
	{
		write(2, "Usage: ./fractol mandelbrot\n", 28);
		write(2, "Usage: ./fractol julia <param1> <param2>\n", 41);
		write(2, "Example: ./fractol julia -0.4 0.6\n", 34);
	}
	else if (msg == 1)
	{
		write(2, "Error: Invalid parameter format\n", 32);
		write(2, "Example: ./fractol julia -0.4 0.6\n", 34);
	}
	exit(1);
}

void	handle(t_fractol *fractol)
{
	if (fractol->craft == MANDELBROT)
		mandelbrot(fractol);
	else if (fractol->craft == JULIA)
		return ;
}
