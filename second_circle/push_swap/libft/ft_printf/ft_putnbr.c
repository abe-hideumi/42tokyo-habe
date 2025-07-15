/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:51:30 by habe              #+#    #+#             */
/*   Updated: 2025/06/10 15:42:44 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_rec(long long nbr)
{
	char	c;
	int		len;

	len = 0;
	if (nbr >= 10)
		len = ft_putnbr_rec(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
	len++;
	return (len);
}

int	ft_putnbr(va_list *args)
{
	long long	nbr;
	int			len;

	nbr = (long long)va_arg(*args, int);
	len = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		len++;
	}
	return (len + ft_putnbr_rec(nbr));
}

int	ft_putnbr_unsigned(va_list *args)
{
	unsigned int	nbr;

	nbr = va_arg(*args, unsigned int);
	return (ft_putnbr_rec((long long)nbr));
}
