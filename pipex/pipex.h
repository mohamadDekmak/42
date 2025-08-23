/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:58:25 by mdekmak           #+#    #+#             */
/*   Updated: 2025/08/23 20:23:46 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "libft/libft.h"

void	process1(int fd[2], char **argv, char **envp);
void	process2(int fd[2], char **argv, char **envp);
void	free_and_exit(char **cmd_args, char *path, int fd, char *msg);
void	error_exit(char *msg);
char	**ft_custom_split(char *s, char c);
int     count_words_quote_aware(char const *s, char c);
int	    word_length_quote_aware(char *s, char c);
void	help_inside_q(int *inside_quote, char *quote_char, int *i, char *str);
void    remove_quotes(char *str);
#endif
