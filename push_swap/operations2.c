/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:01:56 by mdekmak           #+#    #+#             */
/*   Updated: 2025/07/19 20:01:56 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	sb(t_stack *b)
{
	if (swap(b))
	{
		write(1, "sb\n", 3);
		return (1);
	}
	return (0);
}

int	ss(t_stack *a, t_stack *b)
{
	if (swap(a) && swap(b))
	{
		write(1, "ss\n", 3);
		return (1);
	}
	return (0);
}

int	pa(t_stack *a, t_stack *b)
{
	if (push(a, b))
	{
		write(1, "pa\n", 3);
		return (1);
	}
	return (0);
}

int	pb(t_stack *b, t_stack *a)
{
	if (push(b, a))
	{
		write(1, "pb\n", 3);
		return (1);
	}
	return (0);
}

int	ra(t_stack *a)
{
	if (rotate(a))
	{
		write(1, "ra\n", 3);
		return (1);
	}
	return (0);
}
