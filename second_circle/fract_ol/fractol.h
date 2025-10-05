/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:42:17 by habe              #+#    #+#             */
/*   Updated: 2025/10/05 11:01:42 by habe             ###   ########.fr       */
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
# define MAX_COUNT 100

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
void	handle(t_fractol *fractol);
int		key_hook(int keycode, t_fractol *fractol);
int		mouse_hook(int button, int x, int y, t_fractol *fractol);

void	fractol_init(t_fractol *fractol, int argc, char **argv);
void	mandelbrot(t_fractol *fractol);
void	julia(t_fractol *fractol);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int		close_window(t_fractol *fractol);

#endif
