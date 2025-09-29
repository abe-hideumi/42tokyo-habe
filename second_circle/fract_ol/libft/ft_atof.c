/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:27:04 by habe              #+#    #+#             */
/*   Updated: 2025/09/29 16:30:06 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atof(const char *nptr)
{
	double	result;
	double	sign;
	int		i;

	result = 0;
	sign = 0;
	i = 0;
	while (ft_isspace(nptr[i]) != 0)
		i++;
}
