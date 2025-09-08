/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:48:53 by habe              #+#    #+#             */
/*   Updated: 2025/06/10 15:31:35 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(va_list *args)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len] != '\0')
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_putpercent(void)
{
	write(1, "%", 1);
	return (1);
}
