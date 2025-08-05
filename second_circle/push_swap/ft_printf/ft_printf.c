/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:57:33 by habe              #+#    #+#             */
/*   Updated: 2025/06/10 15:11:22 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_frag_check(const char *format, va_list *args)
{
	unsigned int	len;

	len = 0;
	if (format[0] == '%' && format[1] == 'c')
		len = ft_putchar(args);
	else if (format[0] == '%' && format[1] == 's')
		len = ft_putstr(args);
	else if (format[0] == '%' && format[1] == '%')
		len = ft_putpercent();
	else if (format[0] == '%' && format[1] == 'p')
		len = ft_putptr(args);
	else if (format[0] == '%' && (format[1] == 'd' || format[1] == 'i'))
		len = ft_putnbr(args);
	else if (format[0] == '%' && format[1] == 'u')
		len = ft_putnbr_unsigned(args);
	else if (format[0] == '%' && format[1] == 'x')
		len = ft_put_lohex(args);
	else if (format[0] == '%' && format[1] == 'X')
		len = ft_put_uphex(args);
	return ((int)len);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				i;
	unsigned int	total_len;

	va_start(args, format);
	total_len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			total_len += ft_frag_check(&format[i], &args);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			total_len++;
		}
	}
	va_end(args);
	return ((int)total_len);
}
