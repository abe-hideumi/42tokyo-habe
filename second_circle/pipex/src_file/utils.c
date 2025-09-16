/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:28:43 by habe              #+#    #+#             */
/*   Updated: 2025/09/16 12:24:15 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	has_slash(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	usage_print_exit(void)
{
	write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
	exit(EXIT_FAILURE);
}
