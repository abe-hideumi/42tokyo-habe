/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:22:35 by habe              #+#    #+#             */
/*   Updated: 2025/09/24 12:50:27 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct s_cmd
{
	char	**argv;
	char	*path;
	int		flag;
}	t_cmd;

typedef struct s_px
{
	t_cmd	*c1;
	t_cmd	*c2;
	int		fd_in;
	int		fd_out;
	int		end_st;
	int		flag;
}	t_px;

void	free_split(char **sp);
void	free_cmd(t_cmd *c1, t_cmd *c2);
void	free_all(t_px *px);
int		has_slash(const char *str);
void	usage_print_exit(void);
int		bad_command(t_cmd *c);
void	cmd_not_print(t_cmd *cmd);
char	**space_tab_split(const char *str);

int		cmd_init(t_cmd *cmd, const char *cmdline, char *const envp[]);
int		connect_pipe(t_px *px, char *const envp[]);
void	open_infile(t_px *px, const char *path);
int		open_outfile(t_px *px, char *path);
void	close_safe(int *fd);

#endif
