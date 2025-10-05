/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:22:39 by habe              #+#    #+#             */
/*   Updated: 2025/10/05 14:50:51 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_color(int count)
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

int	set_calc(double z_re, double z_im, double c_re, double c_im)
{
	double	re_tmp;
	int		count;

	count = 0;
	while (count < MAX_COUNT)
	{
		if ((z_re * z_re) + (z_im * z_im) > 4.0)
			break ;
		re_tmp = (z_re * z_re) - (z_im * z_im) + c_re;
		z_im = 2.0 * z_re * z_im + c_im;
		z_re = re_tmp;
		count++;
	}
	return (count);
}

void	pixel_to_complex(t_fractol *fractol, int x, int y)
{
	fractol->z_re = (x - WIDTH / 2.0) * (4.0 / WIDTH) / \
					fractol->zoom + fractol->offset_x;
	fractol->z_im = (y - HEIGHT / 2.0) * (4.0 / WIDTH) / \
					fractol->zoom + fractol->offset_y;
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	unsigned int	*row;

	row = (unsigned int *)(img->addr + y * img->line_length);
	row[x] = color;
}
