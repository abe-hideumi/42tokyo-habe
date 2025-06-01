/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:50:23 by habe              #+#    #+#             */
/*   Updated: 2025/05/30 15:44:44 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *c)
{
	size_t	length;

	length = 0;
	while (c[length] != '\0')
	{
		length++;
	}
	return (length);
}

// int	main(void)
// {
// 	char	a;

// 	a = "tokyo";
// 	printf("%d\n", ft_strlen(a));
// 	return (0);
// }
