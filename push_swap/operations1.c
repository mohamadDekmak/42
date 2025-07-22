/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:46:07 by mdekmak           #+#    #+#             */
/*   Updated: 2025/07/19 18:46:07 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	swap(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s || !s->top || !s->top->next)
		return (0);
	first = s->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	s->top = second;
	return (1);
}

int	push(t_stack *s1, t_stack *s2)
{
	t_node	*element;

	if (!s1 || !s2 || !s2->top)
		return (0);
	element = s2->top;
	s2->top = s2->top->next;
	element->next = s1->top;
	s1->top = element;
	return (1);
}

int	rotate(t_stack *s)
{
	t_node	*old_top;
	t_node	*last;

	if (!s || !s->top || !s->top->next)
		return (0);
	old_top = s->top;
	s->top = old_top->next;
	old_top->next = NULL;
	last = s->top;
	while (last->next)
		last = last->next;
	last->next = old_top;
	return (1);
}

int	reverse_rotate(t_stack *s)
{
	t_node	*temp;
	t_node	*last;

	if (!s || !s->top || !s->top->next)
		return (0);
	temp = s->top;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = s->top;
	s->top = last;
	return (1);
}

int	sa(t_stack *a)
{
	if (swap(a))
	{
		write(1, "sa\n", 3);
		return (1);
	}
	return (0);
}
