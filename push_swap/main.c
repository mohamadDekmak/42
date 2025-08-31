/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:33:41 by mdekmak           #+#    #+#             */
/*   Updated: 2025/07/20 10:33:41 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_pos;

	while (get_size(a) > 3)
	{
		min_pos = get_min_pos(a);
		if (min_pos <= get_size(a) / 2)
		{
			while (min_pos > 0)
			{
				ra(a);
				min_pos--;
			}
		}
		else
		{
			help_sort_five(a, &min_pos);
		}
		pb(b, a);
	}
	sort_three(a);
	while (get_size(b) > 0)
		pa(a, b);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (get_size(a) <= 3)
		sort_three(a);
	else if (get_size(a) <= 5)
		sort_five(a, b);
	else
	{
		assign_indices(a);
		radix_sort(a, b);
	}
}

long long	ft_atoll(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_atoi_custom(char *str, t_stack *s, char	**split_args)
{
	long long	val;

	val = ft_atoll(str);
	if (val > 2147483647 || val < -2147483648)
	{
		if (s)
			free_s(s);
		if (split_args)
			free_split(split_args);
		write(2, "Error\n", 6);
		exit(1);
	}
	return ((int)val);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc >= 2)
	{
		a = get_data(argc, argv);
		if (!a)
			write(2, "Error\n", 6);
		else if (is_dupp(a))
		{
			free_s(a);
			write(2, "Error\n", 6);
		}
		else if (sorted(a))
			free_s(a);
		else
		{
			b = malloc(sizeof(t_stack));
			b->top = NULL;
			sort_stack(a, b);
			free_s(a);
			free_s(b);
		}
	}
	return (0);
}
