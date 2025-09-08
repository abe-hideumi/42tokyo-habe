/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:22:35 by habe              #+#    #+#             */
/*   Updated: 2025/09/08 18:42:51 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct s_cmd
{
	char	**argv;
	char	*path;
}	t_cmd;

void	free_split(char **sp);
void	free_all(char **sp_1, char **sp_2);

char	**space_tab_split(const char *str);
int	cmd_init(t_cmd *cmd, const char *cmdline, char **envp);

int	has_slash(const char *str);

void	usage_print_exit(void);

#endif

//functions open, close, read, write, malloc, free, perror
//			strerror, access, dup, dup2, execve, exit, fork
//			pipe, unlink, wait, waitpid
