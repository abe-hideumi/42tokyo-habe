/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:14:15 by habe              #+#    #+#             */
/*   Updated: 2025/05/30 15:43:19 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ans;
	size_t	total_size;

	if (nmemb != 0 && size > __SIZE_MAX__ / nmemb)
		return (NULL);
	total_size = nmemb * size;
	ans = malloc(total_size);
	if (ans == NULL)
		return (NULL);
	ft_bzero(ans, total_size);
	return (ans);
}
