/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:39:27 by mdekmak           #+#    #+#             */
/*   Updated: 2025/07/19 18:39:27 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H
# include <unistd.h>
# include "libft/libft.h"

typedef struct n
{
	int			data;
	struct n	*next;
	int			index;
}	t_node;

typedef struct s
{
	t_node	*top;
}	t_stack;

int		swap(t_stack *s);
int		push(t_stack *s1, t_stack *s2);
int		rotate(t_stack *s);
int		reverse_rotate(t_stack *s);
int		sa(t_stack *a);
int		sb(t_stack *b);
int		ss(t_stack *a, t_stack *b);
int		pa(t_stack *a, t_stack *b);
int		pb(t_stack *b, t_stack *a);
int		ra(t_stack *a);
int		rb(t_stack *b);
int		rr(t_stack *a, t_stack *b);
int		rra(t_stack *a);
int		rrb(t_stack *b);
int		rrr(t_stack *a, t_stack *b);
void	free_s(t_stack	*s);
t_node	*create_t_node(int data);
t_stack	*get_data(int argc, char **argv);
int		is_valid_n(char *str);
void	add_node_to_s(t_stack	*s, t_node	*new);
int		is_dupp(t_stack	*s);
int		sorted(t_stack *s);
#endif