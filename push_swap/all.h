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
int		get_size(t_stack *s);
void	sort_stack(t_stack *a, t_stack *b);
void	assign_indices(t_stack *a);
int		get_bit(int num, int bit_pos);
int		get_max_bits(t_stack *a);
void	radix_sort(t_stack *a, t_stack *b);
char	**custom_ft_split(char *str, char *charset);
void	free_split(char **split);
int		get_min_pos(t_stack *s);
void	help_sort_five(t_stack *s, int *min_pos);
void	sort_three(t_stack *a);
int		ft_atoi_custom(char *str, t_stack *s, char	**split_args);
#endif
