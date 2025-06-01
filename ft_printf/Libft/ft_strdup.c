/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:14:18 by habe              #+#    #+#             */
/*   Updated: 2025/05/30 15:44:26 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ans;
	size_t	s_len;

	s_len = ft_strlen(s);
	ans = malloc(s_len + 1);
	if (ans == NULL)
		return (NULL);
	ft_strlcpy(ans, s, s_len + 1);
	return (ans);
}
