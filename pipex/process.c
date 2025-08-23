/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:59:54 by mdekmak           #+#    #+#             */
/*   Updated: 2025/08/21 18:59:54 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_cmd_array(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}

static void	cleanup_and_exit(char **cmd, char *cmd_path, int fd_to_close, char *error_msg)
{
	free_cmd_array(cmd);
	if (cmd_path)
		free(cmd_path);
	if (fd_to_close >= 0)
		close(fd_to_close);
	perror(error_msg);
	exit(1);
}

void process1(int fd[2], char **argv, char **envp)
{
	int		infile;
	char	**cmd;
	char	*cmd_path;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		(perror("infile"), exit(1));
	cmd = ft_split(argv[2], ' ');
	if (!cmd)
		(perror("ft_split failed"), exit(1));
	cmd_path = get_cmd_path(cmd[0], envp);
	if (!cmd_path)
		cleanup_and_exit(cmd, NULL, infile, "Command not found");
		dup2(input_fd, STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	if (input_fd != STDIN_FILENO)
		close(input_fd);
	if (output_fd != STDOUT_FILENO)
		close(output_fd);
	close(fd[0]);
	close(fd[1]);
	execve(cmd_path, cmd, envp);
	cleanup_and_exit(cmd, cmd_path, -1, "execve");
}

void process2(int fd[2], char **argv, char **envp)
{
	int		outfile;
	char	**cmd;
	char	*cmd_path;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		(perror("outfile"), exit(1));
	cmd = ft_split(argv[3], ' ');
	if (!cmd)
		(perror("ft_split failed"), exit(1));
	cmd_path = get_cmd_path(cmd[0], envp);
	if (!cmd_path)
		cleanup_and_exit(cmd, NULL, outfile, "Command not found");
		dup2(input_fd, STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	if (input_fd != STDIN_FILENO)
		close(input_fd);
	if (output_fd != STDOUT_FILENO)
		close(output_fd);
	close(fd[0]);
	close(fd[1]);
	execve(cmd_path, cmd, envp);
	cleanup_and_exit(cmd, cmd_path, -1, "execve");
}
