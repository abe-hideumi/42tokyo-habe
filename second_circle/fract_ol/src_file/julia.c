/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:09:39 by habe              #+#    #+#             */
/*   Updated: 2025/10/05 14:57:36 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia(t_fractol *fractol)
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
			count = set_calc(fractol->z_re, fractol->z_im, \
								fractol->p1, fractol->p2);
			color = get_color(count);
			my_mlx_pixel_put(&fractol->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, \
						fractol->win, fractol->img.img, 0, 0);
}
