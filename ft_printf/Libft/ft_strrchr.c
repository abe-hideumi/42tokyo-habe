/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:40:02 by habe              #+#    #+#             */
/*   Updated: 2025/05/30 15:44:55 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			p = ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		p = ((char *)&s[i]);
	return (p);
}
