/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:22:35 by habe              #+#    #+#             */
/*   Updated: 2025/09/16 19:44:45 by habe             ###   ########.fr       */
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
}	t_cmd;

typedef struct s_px
{
	int	fd_in;
	int	fd_out;
	int	end_st;
}	t_px;

void	free_split(char **sp);
void	free_all(t_cmd *c1, t_cmd *c2);
int		has_slash(const char *str);
void	usage_print_exit(void);
int		bad_command(t_cmd *c);
char	**space_tab_split(const char *str);

int		cmd_init(t_cmd *cmd, const char *cmdline, char *const envp[]);
int		connect_pipe(t_px *px, t_cmd *c1, t_cmd *c2, char *const envp[]);
void	open_infile(t_px *px, const char *path);
int		open_outfile(t_px *px, char *path);
void	close_safe(int *fd);

#endif
