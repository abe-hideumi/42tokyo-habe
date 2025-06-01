/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:21:31 by habe              #+#    #+#             */
/*   Updated: 2025/05/30 15:48:12 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ans;
	long long	nbr;
	int		len;

	nbr = (long)n;
	len = count_digits(nbr);
	ans = malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	ans[len] = '\0';
	if (nbr < 0)
	{
		ans[0] = '-';
		nbr = -nbr;
	}
	else if (nbr == 0)
		ans[0] = '0';
	while (nbr > 0)
	{
		ans[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (ans);
}
