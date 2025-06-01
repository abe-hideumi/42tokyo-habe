/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:11:23 by habe              #+#    #+#             */
/*   Updated: 2025/05/30 15:43:45 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_cpy;
	const unsigned char	*s2_cpy;
	size_t				i;

	s1_cpy = (const unsigned char *)s1;
	s2_cpy = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_cpy[i] != s2_cpy[i])
			return ((int)s1_cpy[i] - (int)s2_cpy[i]);
		i++;
	}
	return (0);
}
