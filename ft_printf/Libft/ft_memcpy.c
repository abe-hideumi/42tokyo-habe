/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:09:49 by habe              #+#    #+#             */
/*   Updated: 2025/05/30 15:43:48 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		((unsigned char *)dest)[count] = \
			((unsigned char *)src)[count];
		count++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	src[] = "tokyo,skytree!";
// 	char	dest[20];

// 	ft_memcpy(dest, src, 14);
// 	printf("コピー後：%s\n", dest);
// 	return (0);
// }
