/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:37:32 by habe              #+#    #+#             */
/*   Updated: 2025/10/02 16:12:29 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	get_color(int iter, int max_iter)
{
	int		r;
	int		g;
	int		b;
	double	t;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / (double)max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

static int	mandelbrot_calc(double c_re, double c_im, int max_iter)
{
	double	z_re;
	double	z_im;
	double	z_re_tmp;
	int		iter;

	z_re = 0.0;
	z_im = 0.0;
	iter = 0;
	while (iter < max_iter)
	{
		if ((z_re * z_re) + (z_im * z_im) > 4.0)
			break ;
		z_re_tmp = (z_re * z_re) - (z_im * z_im) + c_re;
		z_im = 2.0 * z_re * z_im + c_im;
		z_re = z_re_tmp;
		iter++;
	}
	return (iter);
}

static void	pixel_to_complex(int x, int y, t_fractol *fractol)
{
	fractol->p1 = (x - WIDTH / 2.0) * (4.0 / WIDTH) / \
					fractol->zoom + fractol->offset_x;
	fractol->p2 = (y - HEIGHT / 2.0) * (4.0 / WIDTH) / \
					fractol->zoom + fractol->offset_y;
}

void	mandelbrot(t_fractol *fractol)
{
	int		x;
	int		y;
	int		iter;
	int		color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_to_complex(x, y, fractol);
			iter = mandelbrot_calc(fractol->p1, fractol->p2, 100);
			color = get_color(iter, 100);
			my_mlx_pixel_put(&fractol->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, \
						fractol->win, fractol->img.img, 0, 0);
}
