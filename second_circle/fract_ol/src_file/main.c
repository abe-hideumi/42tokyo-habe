/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:57:10 by habe              #+#    #+#             */
/*   Updated: 2025/10/05 13:02:34 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	unsigned int	*row;

	row = (unsigned int *)(img->addr + y * img->line_length);
	row[x] = color;
}

int	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
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

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc < 2)
		usage_print(USAGE);
	fractol_init(&fractol, argc, argv);
	fractol_display_init(&fractol);
	handle(&fractol);
	mlx_mouse_hook(fractol.win, mouse_hook, &fractol);
	mlx_key_hook(fractol.win, key_hook, &fractol);
	mlx_hook(fractol.win, 17, 0, close_window, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
