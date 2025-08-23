/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:04:44 by mdekmak           #+#    #+#             */
/*   Updated: 2025/08/23 17:52:07 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

static char	*search_in_paths(char *cmd, char **paths)
{
	int		i;
	char	*path;
	char	*temp;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (NULL);
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (path && access(path, X_OK) == 0)
		{
			free_paths(paths);
			return (path);
		}
		if (path)
			free(path);
		i++;
	}
	free_paths(paths);
	return (NULL);
}

static char	*get_path(char *cmd, char **envp)
{
	char	*env_paths;
	char	**paths;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	env_paths = (*envp + 5);
	paths = ft_split(env_paths, ':');
	if (!paths)
		return (NULL);
	return (search_in_paths(cmd, paths));
}

void	process1(int fd[2], char **argv, char **envp)
{
	int		infile;
	char	**cmd_w_args;
	char	*cmd_path;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_exit("infile");
	cmd_w_args = ft_custom_split(argv[2], ' ');
	if (!cmd_w_args)
		error_exit("ft_split failed");
	cmd_path = get_path(cmd_w_args[0], envp);
	if (!cmd_path)
		free_and_exit(cmd_w_args, NULL, infile, "command not found");
	if (dup2(infile, STDIN_FILENO) < 0)
		free_and_exit(cmd_w_args, cmd_path, infile, "dup2 in");
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		free_and_exit(cmd_w_args, cmd_path, infile, "dup2 out");
	close(infile);
	close(fd[0]);
	close(fd[1]);
	execve(cmd_path, cmd_w_args, envp);
	free_and_exit(cmd_w_args, cmd_path, -1, "process1");
}

void	process2(int fd[2], char **argv, char **envp)
{
	int		outfile;
	char	**cmd_w_args;
	char	*cmd_path;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error_exit("outfile");
	cmd_w_args = ft_custom_split(argv[3], ' ');
	if (!cmd_w_args)
		error_exit("ft_split failed");
	cmd_path = get_path(cmd_w_args[0], envp);
	if (!cmd_path)
		free_and_exit(cmd_w_args, NULL, outfile, "command not found");
	if (dup2(fd[0], STDIN_FILENO) < 0)
		free_and_exit(cmd_w_args, cmd_path, outfile, "dup2 in");
	if (dup2(outfile, STDOUT_FILENO) < 0)
		free_and_exit(cmd_w_args, cmd_path, outfile, "dup2 out");
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	execve(cmd_path, cmd_w_args, envp);
	free_and_exit(cmd_w_args, cmd_path, -1, "process2");
}
