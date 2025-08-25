/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:22:35 by habe              #+#    #+#             */
/*   Updated: 2025/08/25 18:16:35 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
}	t_cmd;




#endif

//functions open, close, read, write, malloc, free, perror
//			strerror, access, dup, dup2, execve, exit, fork
//			pipe, unlink, wait, waitpid
