/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:37:18 by mdekmak           #+#    #+#             */
/*   Updated: 2025/07/20 10:37:18 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	is_valid_n(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_stack	*get_data_for_args_two(char **argv, t_stack *s)
{
	char	**split_args;
	int		i;
	t_node	*n;
	int		value;

	split_args = custom_ft_split(argv[1], " \t");
	if (!split_args)
		return (free_s(s), NULL);
	i = 0;
	while (split_args[i])
	{
		if (!is_valid_n(split_args[i]))
			return (free_split(split_args), free_s(s), NULL);
		value = ft_atoi_custom(split_args[i], s, split_args);
		n = create_t_node(value);
		if (!n)
			return (free_split(split_args), free_s(s), NULL);
		add_node_to_s(s, n);
		i++;
	}
	free_split(split_args);
	return (s);
}

t_stack	*get_data_for_args_multiple(int argc, char **argv, t_stack *s)
{
	t_node	*n;
	int		i;
	int		value;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_n(argv[i]))
			return (free_s(s), NULL);
		value = ft_atoi_custom(argv[i], s, NULL);
		n = create_t_node(value);
		if (!n)
			return (free_s(s), NULL);
		add_node_to_s(s, n);
		i++;
	}
	return (s);
}

t_stack	*get_data(int argc, char **argv)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	if (argc == 2)
		return (get_data_for_args_two(argv, s));
	else
		return (get_data_for_args_multiple(argc, argv, s));
	return (s);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
