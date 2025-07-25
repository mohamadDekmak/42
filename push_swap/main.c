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

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i = 0;

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
		else{
			b = malloc(sizeof(t_stack));
			b->top = NULL;
			sort_stack(a, b);
			// t_node * temp = a->top;
			// while (temp)
			// {
			// 	printf("%d %d\n",temp->data, temp->index);
			// 	temp = temp->next;
			// }
		}
	}
	return (0);
}
