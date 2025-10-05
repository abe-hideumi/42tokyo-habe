/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:37:32 by habe              #+#    #+#             */
/*   Updated: 2025/10/05 13:05:04 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	get_color(int count)
{
	int		r;
	int		g;
	int		b;
	double	t;

	if (count == MAX_COUNT)
		return (0x000000);
	t = (double)count / (double)MAX_COUNT;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

static int	set_calc(double c_re, double c_im)
{
	double	re;
	double	im;
	double	re_tmp;
	int		count;

	re = 0.0;
	im = 0.0;
	count = 0;
	while (count < MAX_COUNT)
	{
		if ((re * re) + (im * im) > 4.0)
			break ;
		re_tmp = (re * re) - (im * im) + c_re;
		im = 2.0 * re * im + c_im;
		re = re_tmp;
		count++;
	}
	return (count);
}

static void	pixel_to_complex(t_fractol *fractol, int x, int y)
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
	int		count;
	int		color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_to_complex(fractol, x, y);
			count = set_calc(fractol->p1, fractol->p2);
			color = get_color(count);
			my_mlx_pixel_put(&fractol->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, \
						fractol->win, fractol->img.img, 0, 0);
}
