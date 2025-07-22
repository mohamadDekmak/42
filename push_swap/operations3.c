/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:02:27 by mdekmak           #+#    #+#             */
/*   Updated: 2025/07/19 20:02:27 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	rb(t_stack *b)
{
	if (rotate(b))
	{
		write(1, "rb\n", 3);
		return (1);
	}
	return (0);
}

int	rr(t_stack *a, t_stack *b)
{
	if (rotate(a) && rotate(b))
	{
		write(1, "rr\n", 3);
		return (1);
	}
	return (0);
}

int	rra(t_stack *a)
{
	if (reverse_rotate(a))
	{
		write(1, "rra\n", 4);
		return (1);
	}
	return (0);
}

int	rrb(t_stack *b)
{
	if (reverse_rotate(b))
	{
		write(1, "rrb\n", 4);
		return (1);
	}
	return (0);
}

int	rrr(t_stack *a, t_stack *b)
{
	if (reverse_rotate(a) && reverse_rotate(b))
	{
		write(1, "rrr\n", 4);
		return (1);
	}
	return (0);
}
