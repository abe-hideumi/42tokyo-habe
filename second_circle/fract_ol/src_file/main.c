/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:57:10 by habe              #+#    #+#             */
/*   Updated: 2025/10/02 15:08:53 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	exit(0);
	return (0);
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

static void	craft_type(t_fractol *fractol, int argc, char **argv)
{
	if (strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		if (argc != 2)
			usage_print(USAGE);
		fractol->craft = MANDELBROT;
		fractol->p1 = 0.0;
		fractol->p2 = 0.0;
	}
	else if (strncmp(argv[1], "julia", 6) == 0)
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

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == 65397)
		close_window(fractol);
	return (0);
}

static void	fractol_init(t_fractol *fractol, int argc, char **argv)
{
	craft_type(fractol, argc, argv);
	fractol->zoom = 1.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc < 2)
		usage_print(USAGE);
	fractol_init(&fractol, argc, argv);
	fractol_display_init(&fractol);
	mlx_key_hook(fractol.win, key_hook, &fractol);
	mlx_hook(fractol.win, 17, 0, close_window, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
