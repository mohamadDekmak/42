/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 20:17:08 by mdekmak           #+#    #+#             */
/*   Updated: 2025/08/23 20:17:08 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_result(int *j, char **result)
{
	while (*j > 0)
		free(result[--(*j)]);
	free(result);
	return ;
}

static void	get_result_quote_aware(char *s, char c, char **result, int *j)
{
	int	i;
	int	len;
	int	k;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = word_length_quote_aware(&s[i], c);
			result[*j] = (char *)malloc(sizeof(char) * (len + 1));
			if (result[*j] == NULL)
				return (free_result(j, result));
			k = 0;
			while (k < len)
				result[*j][k++] = s[i++];
			result[*j][k] = '\0';
			remove_quotes(result[*j]);
			(*j)++;
		}
		else
			i++;
	}
	result[*j] = NULL;
}

char	**ft_custom_split(char *s, char c)
{
	char	**result;
	int		j;
	int		count;

	if (s == NULL)
		return (NULL);
	count = count_words_quote_aware(s, c);
	j = 0;
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
		return (NULL);
	get_result_quote_aware(s, c, result, &j);
	return (result);
}
