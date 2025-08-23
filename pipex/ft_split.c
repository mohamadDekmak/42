/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:14:07 by mdekmak           #+#    #+#             */
/*   Updated: 2025/08/23 20:23:51 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

int	count_words_quote_aware(char const *s, char c)
{
	int		i;
	int		word_count;
	int		inside_quote;
	char	quote_char;

	quote_char = '\0';
	i = 0;
	inside_quote = 0;
	word_count = 0;
	while (s[i])
	{
		if (!inside_quote && is_quote(s[i]))
		{
			inside_quote = 1;
			quote_char = s[i];
		}
		else if (inside_quote && s[i] == quote_char)
		{
			inside_quote = 0;
		}
		if (s[i] != c && (i == 0 || (s[i - 1] == c && !inside_quote)))
			word_count++;
		i++;
	}
	return (word_count);
}

int	word_length_quote_aware(char *s, char c)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (s[i])
	{
		if (!quote && is_quote(s[i]))
			quote = s[i];
		else if (quote && s[i] == quote)
			quote = 0;
		else if (!quote && s[i] == c)
			break ;
		i++;
	}
	return (i);
}

void	help_inside_q(int *inside_quote, char *quote_char, int *i, char *str)
{
	*inside_quote = 1;
	*quote_char = str[*i];
	*i = *i + 1;
}

void	remove_quotes(char *str)
{
	int		i;
	int		j;
	char	quote_char;
	int		inside_quote;

	i = 0;
	j = 0;
	inside_quote = 0;
	quote_char = '\0';
	while (str[i])
	{
		if (!inside_quote && is_quote(str[i]))
		{
			help_inside_q(&inside_quote, &quote_char, &i, str);
			continue ;
		}
		else if (inside_quote && str[i] == quote_char)
		{
			inside_quote = 0;
			i++;
			continue ;
		}
		str[j++] = str[i++];
	}
	str[j] = '\0';
}
