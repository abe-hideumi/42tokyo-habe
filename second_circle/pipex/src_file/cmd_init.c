/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:36:44 by habe              #+#    #+#             */
/*   Updated: 2025/09/14 15:36:38 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_env_value(char *const envp[], const char *key)
{
	size_t	klen;
	int		i;

	if (envp == NULL || key == NULL)
		return (NULL);
	i = 0;
	klen = ft_strlen(key);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], key, klen) == 0 && envp[i][klen] == '=')
			return (&envp[i][klen + 1]);
		i++;
	}
	return (NULL);
}

static char	*try_join_exec(const char *dir, const char *bin)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	if (tmp == NULL)
		return (NULL);
	full = ft_strjoin(tmp, bin);
	free(tmp);
	return (full);
}

static char	*serch_path(const char *cmd, char *const envp[])
{
	char	*path;
	char	**dirs;
	char	*full;
	int		i;

	path = get_env_value(envp, "PATH");
	if (path == NULL)
		return (NULL);
	dirs = ft_split(path, ':');
	if (dirs == NULL)
		return (NULL);
	i = 0;
	while (dirs[i] != NULL)
	{
		full = try_join_exec(dirs[i], cmd);
		if (full == NULL)
			return (free_split(dirs), NULL);
		if (access(full, X_OK) == 0)
			return (free_split(dirs), full);
		free(full);
		i++;
	}
	return (free_split(dirs), NULL);
}

static char	*get_the_path(char **argv, char *const envp[])
{
	if (argv == NULL || argv[0] == NULL || argv[0][0] == '\0')
		return (NULL);
	if (has_slash(argv[0]) != 0)
	{
		if (access(argv[0], X_OK) == 0)
			return (ft_strdup(argv[0]));
		return (NULL);
	}
	return (serch_path(argv[0], envp));
}

int	cmd_init(t_cmd *cmd, const char *cmdline, char *const envp[])
{
	if (cmd == NULL || cmdline == NULL || cmdline[0] == '\0')
		return (-1);
	cmd->argv = space_tab_split(cmdline);
	if (cmd->argv == NULL || cmd->argv[0] == NULL)
	{
		free_split(cmd->argv);
		cmd->argv = NULL;
		return (-1);
	}
	cmd->path = get_the_path(cmd->argv, envp);
	if (cmd->path == NULL)
	{
		free_split(cmd->argv);
		cmd->argv = NULL;
		return (-1);
	}
	return (0);
}
