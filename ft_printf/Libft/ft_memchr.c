/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:42:05 by habe              #+#    #+#             */
/*   Updated: 2025/05/30 15:43:41 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_cpy;
	size_t				i;

	s_cpy = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_cpy[i] == (unsigned char)c)
			return ((void *)&s_cpy[i]);
		i++;
	}
	return (NULL);
}
