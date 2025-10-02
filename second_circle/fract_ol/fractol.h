/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:42:17 by habe              #+#    #+#             */
/*   Updated: 2025/10/02 15:13:31 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define WIDTH 800
# define HEIGHT 600

# define JULIA 0
# define MANDELBROT 1
# define USAGE 0
# define INVALID 1

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fractol
{
	t_data	img;
	void	*mlx;
	void	*win;
	int		craft;
	double	p1;
	double	p2;
	double	zoom;
	double	offset_x;
	double	offset_y;
}	t_fractol;

int		param_check(const char *nptr);
void	usage_print(int msg);
int	key_hook(int keycode, t_fractol *fractol);

#endif
