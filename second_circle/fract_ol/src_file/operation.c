/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:41:11 by habe              #+#    #+#             */
/*   Updated: 2025/10/05 17:24:40 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == ESC)
		close_window(fractol);
	if (keycode == LEFT)
	{
		fractol->offset_x -= 0.1 / fractol->zoom;
		handle(fractol);
	}
	if (keycode == RIGHT)
	{
		fractol->offset_x += 0.1 / fractol->zoom;
		handle(fractol);
	}
	if (keycode == UP)
	{
		fractol->offset_y -= 0.1 / fractol->zoom;
		handle(fractol);
	}
	if (keycode == DOWN)
	{
		fractol->offset_y += 0.1 / fractol->zoom;
		handle(fractol);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	double	mouse_re;
	double	mouse_im;

	if (button == 4 || button == 5)
	{
		mouse_re = (x - WIDTH / 2.0) * (4.0 / WIDTH) / fractol->zoom
			+ fractol->offset_x;
		mouse_im = (y - HEIGHT / 2.0) * (4.0 / WIDTH) / fractol->zoom
			+ fractol->offset_y;

		if (button == 4)
			fractol->zoom *= 1.4;
		else if (button == 5)
			fractol->zoom /= 1.4;

		fractol->offset_x = mouse_re - (x - WIDTH / 2.0) * (4.0 / WIDTH)
			/ fractol->zoom;
		fractol->offset_y = mouse_im - (y - HEIGHT / 2.0) * (4.0 / WIDTH)
			/ fractol->zoom;

		handle(fractol);
	}
	return (0);
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
