/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:22:56 by fbachman          #+#    #+#             */
/*   Updated: 2026/07/01 16:25:09 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>

//structs
typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}			t_stack;

//parsing

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_parsing
{
	t_strategy	strategy;
	bool		bench;
	bool		has_strategy;
	bool		seen_number;
}	t_parsing;

//operations
int		ft_push(t_stack *dest, t_stack *src);
int		ft_swap(t_stack *stack);
int		ft_rotate(t_stack *stack);
int		ft_rrotate(t_stack *stack);

//print operations
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

//populate stack
t_node	*ft_create_node(int value);
void	ft_init_stack(t_stack *stack);
void	ft_clear_stack(t_stack *stack);
void	ft_populate_stack(t_stack *stack_a, int *parsed_array, int array_size);

//disorder
double	ft_compute_disorder(t_stack *stack);
void	ft_adaptive_strategy(t_stack *a, t_stack *b);

//lst aux
t_node	*ft_pop_node(t_stack *stack, t_node *node);
int		ft_push_back(t_stack *stack, t_node *node);
int		ft_push_front(t_stack *stack, t_node *node);

//sorting operations | small stacks
int		ft_find_min(t_stack *stack);
void	ft_sort_three(t_stack *st_a);
void	ft_sort_four(t_stack *a, t_stack *b);
void	ft_sort_five(t_stack *a, t_stack *b);

//sorting operations | simple algorithm
void	ft_bubble_sort(t_stack *a);

#endif