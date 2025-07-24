/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:27:07 by mdekmak           #+#    #+#             */
/*   Updated: 2025/07/24 19:27:07 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	sort_three(t_stack *a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (a->top)->data;
	n2 = (a->top)->next->data;
	n3 = (a->top)->next->next->data;
	if (n3 < n1 && n3 < n2 && n2 < n1)
	{
		ra(a);
		sa(a);
	}
	else if (n3 < n1 && n3 < n2 && n1 < n2)
		rra(a);
	else if (n2 < n1 && n2 < n3 && n3 < n1)
		ra(a);
	else if (n2 < n1 && n1 < n3 && n1 < n3)
		sa(a);
	else if (n1 < n2 && n3 < n2)
	{
		rra(a);
		sa(a);
	}
}

int	get_min(t_stack *s)
{
	t_node	*temp;
	int		min;

	temp = s->top;
	min = temp->data;
	temp = temp->next;
	while (temp)
	{
		if (min > temp->data)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

int	get_min_pos(t_stack *s)
{
	t_node	*temp;
	int		min;
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	temp = s->top;
	min = temp->data;
	temp = temp->next;
	while (temp)
	{
		if (min > temp->data)
		{
			min = temp->data;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}
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
			min_pos = get_size(a) - min_pos;
			while (min_pos > 0)
			{	
				rra(a);
				min_pos--;
			}
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
}
