/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:14:15 by habe              #+#    #+#             */
/*   Updated: 2025/05/05 20:12:08 by habe             ###   ########.fr       */
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
