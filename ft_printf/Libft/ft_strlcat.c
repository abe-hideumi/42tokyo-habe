/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:31:40 by habe              #+#    #+#             */
/*   Updated: 2025/05/30 15:44:37 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_l;
	size_t	src_l;
	size_t	i;

	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	i = 0;
	if (dst_l >= size)
		return (size + src_l);
	while (i < size - dst_l - 1 && src[i] != '\0')
	{
		dst[i + dst_l] = src[i];
		i++;
	}
	dst[i + dst_l] = '\0';
	return (dst_l + src_l);
}
