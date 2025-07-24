/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:09:40 by mdekmak           #+#    #+#             */
/*   Updated: 2025/07/20 12:09:40 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	free_s(t_stack	*s)
{
	t_node	*temp;

	while (s->top)
	{
		temp = s->top;
		s->top = s->top->next;
		free(temp);
	}	
}

t_node	*create_t_node(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->index = -1;
	return (new);
}

void	add_node_to_s(t_stack	*s, t_node	*new)
{
	t_node	*temp;

	temp = s->top;
	if (!s->top)
		s->top  = new;
	else{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int	is_dupp(t_stack	*s)
{
	t_node	*temp;
	t_node	*temp1;

	temp = s->top;
	while (temp)
	{
		temp1 = s->top;
		while (temp1)
		{
			if ((temp1->data == temp->data) && temp != temp1)
				return (1);
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
	return (0);
}

int	sorted(t_stack *s)
{
	t_node	*temp;
	t_node	*temp1;

	temp = s->top;
	while (temp)
	{
		temp1 = temp->next;
		while (temp1)
		{
			if ((temp1->data < temp->data))
				return (0);
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
	return (1);
}