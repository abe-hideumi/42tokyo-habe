/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:28:36 by habe              #+#    #+#             */
/*   Updated: 2025/10/02 16:25:59 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	craft_type(t_fractol *fractol, int argc, char **argv)
{
	if (strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		if (argc != 2)
			usage_print(USAGE);
		fractol->craft = MANDELBROT;
		fractol->p1 = 0.0;
		fractol->p2 = 0.0;
		fractol->offset_x = -0.5;
	}
	else if (strncmp(argv[1], "julia", 5) == 0)
	{
		if (argc != 4)
			usage_print(USAGE);
		if (param_check(argv[2]) != 0 || param_check(argv[3]) != 0)
			usage_print(INVALID);
		fractol->craft = JULIA;
		fractol->p1 = ft_atof(argv[2]);
		fractol->p2 = ft_atof(argv[3]);
		fractol->offset_x = 0.0;
	}
	else
		usage_print(USAGE);
}

void	fractol_init(t_fractol *fractol, int argc, char **argv)
{
	craft_type(fractol, argc, argv);
	fractol->zoom = 1.0;
	fractol->offset_y = 0.0;
}
