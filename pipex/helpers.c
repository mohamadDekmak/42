/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:32:10 by mdekmak           #+#    #+#             */
/*   Updated: 2025/08/21 23:32:10 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_paths(char **paths)
{
	int	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

static char	*build_full_path(char *dir, char *cmd)
{
	char	*temp = ft_strjoin(dir, "/");
	if (!temp)
		return (NULL);
	char *full_path = ft_strjoin(temp, cmd);
	free(temp);
	return (full_path);
}

static char	*get_path_env(char **envp)
{
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	return (*envp + 5);
}

static char	*search_in_paths(char *cmd, char **paths)
{
	int		i;
	char	*full_path;

	i = 0;
	while (paths[i])
	{
		full_path = build_full_path(paths[i], cmd);
		if (full_path && access(full_path, X_OK) == 0)
		{
			free_paths(paths);
			return (full_path);
		}
		if (full_path)
			free(full_path);
		i++;
	}
	free_paths(paths);
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths

	path_env = get_path_env(envp); // return Path value
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	return (search_in_paths(cmd, paths));
}
