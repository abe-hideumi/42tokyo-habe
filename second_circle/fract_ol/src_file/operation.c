/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:41:11 by habe              #+#    #+#             */
/*   Updated: 2025/10/02 16:57:01 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == 65307)
		close_window(fractol);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractol->zoom *= 1.1;
	else if (button == 5)
		fractol->zoom /= 1.1;
	else
		return (0);
	handle(fractol);
	return (0);
}
