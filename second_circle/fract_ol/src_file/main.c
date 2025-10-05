/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:57:10 by habe              #+#    #+#             */
/*   Updated: 2025/10/05 16:53:21 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
