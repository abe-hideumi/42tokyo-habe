/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:27:48 by habe              #+#    #+#             */
/*   Updated: 2025/08/21 17:27:36 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				nbr;
	int				order;
	int				group;
	int				sign;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

t_node	*node_new(int nbr);
t_node	*node_last(t_node *lst);
void	node_add_back(t_node **lst, t_node *new);
int		put_in_stack_a(t_stack *a, t_stack *b, char **nbrs, int sp);

void	small_sort(t_stack *a, t_stack *b);
void	push_to_b(t_stack *a, t_stack *b, int g_size);
void	push_to_a(t_stack *a, t_stack *b);
int		check_atoi(t_stack *a, t_stack *b, char **sp, const char *str);

void	error_exit(t_stack *a, t_stack *b, char **sp);
void	free_split(char **nbrs);
void	free_all(t_stack *a, t_stack *b);

#endif
