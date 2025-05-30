/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:16:37 by habe              #+#    #+#             */
/*   Updated: 2025/05/05 17:33:09 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	src;
	size_t			count;

	src = (unsigned char)c;
	count = 0;
	while (count < n)
	{
		((unsigned char *)s)[count] = src;
		count++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	str[20];

// 	ft_memset(str, 'A', 10);
// 	printf("変更前：%s\n", str);
// 	ft_memset(str, '/', 5);
// 	printf("変更後：%s\n", str);
// 	return (0);
// }
