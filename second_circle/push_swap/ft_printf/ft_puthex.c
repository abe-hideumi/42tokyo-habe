/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:49:14 by habe              #+#    #+#             */
/*   Updated: 2025/06/10 15:34:26 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_lohex(va_list *args)
{
	char			*hex;
	char			buf[9];
	unsigned int	n;
	int				i;
	int				len;

	n = va_arg(*args, unsigned int);
	hex = "0123456789abcdef";
	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	while (n > 0)
	{
		buf[i] = hex[n % 16];
		n /= 16;
		i++;
	}
	len = i;
	while (--i >= 0)
		write(1, &buf[i], 1);
	return (len);
}

int	ft_put_uphex(va_list *args)
{
	char			*hex;
	char			buf[9];
	unsigned int	n;
	int				i;
	int				len;

	n = va_arg(*args, unsigned int);
	hex = "0123456789ABCDEF";
	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	while (n > 0)
	{
		buf[i] = hex[n % 16];
		n /= 16;
		i++;
	}
	len = i;
	while (--i >= 0)
		write(1, &buf[i], 1);
	return (len);
}
