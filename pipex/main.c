/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:56:18 by mdekmak           #+#    #+#             */
/*   Updated: 2025/08/23 15:32:46 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	p1;
	pid_t	p2;

	if (argc != 5)
		return (write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 38), 1);
	if (access(argv[1], F_OK) != 0)
		return (perror("infile"), 1);
	if (pipe(fd) == -1)
		return (perror("pipe"), 1);
	p1 = fork();
	if (p1 == -1)
		return (perror("fork"), 1);
	if (p1 == 0)
		process1(fd, argv, envp);
	p2 = fork();
	if (p2 == -1)
		return (perror("fork"), 1);
	if (p2 == 0)
		process2(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(p1, NULL, 0);
	waitpid(p2, NULL, 0);
	return (0);
}
