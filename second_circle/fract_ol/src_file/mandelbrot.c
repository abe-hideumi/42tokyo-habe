/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:37:32 by habe              #+#    #+#             */
/*   Updated: 2025/10/05 17:10:38 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
			count = set_calc(0.0, 0.0, fractol->z_re, fractol->z_im);
			color = get_color(count);
			my_mlx_pixel_put(&fractol->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, \
						fractol->win, fractol->img.img, 0, 0);
}
