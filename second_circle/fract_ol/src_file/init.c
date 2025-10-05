/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:28:36 by habe              #+#    #+#             */
/*   Updated: 2025/10/05 14:53:17 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	craft_type(t_fractol *fractol, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		if (argc != 2)
			usage_print(USAGE);
		fractol->craft = MANDELBROT;
		fractol->p1 = 0.0;
		fractol->p2 = 0.0;
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
			usage_print(USAGE);
		if (param_check(argv[2]) != 0 || param_check(argv[3]) != 0)
			usage_print(INVALID);
		fractol->craft = JULIA;
		fractol->p1 = ft_atof(argv[2]);
		fractol->p2 = ft_atof(argv[3]);
	}
	else
		usage_print(USAGE);
}

void	fractol_init(t_fractol *fractol, int argc, char **argv)
{
	craft_type(fractol, argc, argv);
	fractol->zoom = 1.0;
	fractol->z_re = 0.0;
	fractol->z_im = 0.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
}

void	fractol_display_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fract'ol");
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img, \
						&fractol->img.bits_per_pixel, \
						&fractol->img.line_length, \
						&fractol->img.endian);
}
