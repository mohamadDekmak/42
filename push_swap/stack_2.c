/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:29:19 by mdekmak           #+#    #+#             */
/*   Updated: 2025/07/24 19:29:19 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	get_size(t_stack *s)
{
	t_node	*temp;
	int		i;

	if (!s || !s->top)
		return (0);
	temp = s->top;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	assign_indices(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = a->top;
	while (current)
	{
		index = 0;
		compare = a->top;
		while (compare)
		{
			if (compare->data < current->data)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	get_bit(int num, int bit_pos)
{
	return ((num >> bit_pos) & 1);
}

int	get_max_bits(t_stack *a)
{
	int	size;
	int	bits;

	size = get_size(a);
	bits = 0;
	while ((1 << bits) < size)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;
	int	size;
	int	i;

	max_bits = get_max_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		size = get_size(a);
		i = 0;
		while (i < size)
		{
			if (get_bit(a->top->index, bit) == 0)
				pb(b, a);
			else
				ra(a);
			i++;
		}
		while (get_size(b) > 0)
			pa(a, b);
		bit++;
	}
}
