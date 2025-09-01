/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:51:32 by habe              #+#    #+#             */
/*   Updated: 2025/06/10 15:44:40 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	ft_putptr_hex(char *buf, uintptr_t addr)
{
	const char	*hex;
	int			len;

	hex = "0123456789abcdef";
	len = 0;
	while (addr > 0)
	{
		buf[len] = hex[addr % 16];
		addr /= 16;
		len++;
	}
	return (len);
}

int	ft_putptr(va_list *args)
{
	void		*ptr;
	uintptr_t	addr;
	char		buf[16];
	int			i;
	int			len;

	ptr = va_arg(*args, void *);
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	addr = (uintptr_t)ptr;
	write(1, "0x", 2);
	if (addr == 0)
		return (write(1, "0", 1) + 2);
	i = ft_putptr_hex(buf, addr);
	len = i + 2;
	while (--i >= 0)
		write(1, &buf[i], 1);
	return (len);
}
