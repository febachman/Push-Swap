/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:22:56 by fbachman          #+#    #+#             */
/*   Updated: 2026/07/03 14:46:35 by fbachman         ###   ########.fr       */
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

void	init_parsing_config(t_parsing *parsing);
int		parse_strategy_flag(char *arg, t_parsing *parsing);
int		parse_bench_flag(char *arg, t_parsing *parsing);
int		parse_flag(char *arg, t_parsing *parsing);

int		is_valid_number(char *token);
int		ft_atol_checked(char *str, int *out);
int		ft_stack_has_value(t_stack *stack, int value);
int		parse_number_token(char *token, t_stack *stack);
int		apply_strategy(t_parsing *parsing, t_stack *a, t_stack *b);

void	free_split(char **tokens);
int		parse_split_tokens(char **tokens, t_stack *a, t_parsing *parsing);
int		parse_args(int argc, char **argv, t_stack *a, t_parsing *parsing);

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

//sorting operations | medium algorithm
void	ft_chunk_sort(t_stack *a, t_stack *b);
void	ft_phase_one(t_stack *a, t_stack *b, int chunk_size);
void	ft_phase_two(t_stack *a, t_stack *b);
int		ft_get_index(t_stack *a, t_stack *b, int value);
int		ft_max_position(t_stack	*stack);

#endif