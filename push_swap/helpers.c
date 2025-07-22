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

t_stack	*get_data(int argc, char **argv)
{
	t_stack	*s;
	t_node	*n;
	int		i;
	int		value;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_n(argv[i]))
			return (free_s(s), NULL);
		value = ft_atoi(argv[i]);
		n = create_t_node(value);
		if (!n)
			return (free_s(s), NULL);
		add_node_to_s(s, n);
		i++;
	}
	return (s);
}
