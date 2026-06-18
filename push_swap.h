/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:22:56 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/18 11:15:10 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

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

//operations
int		ft_push(t_stack *dest, t_stack *src);
int		ft_swap(t_stack *stack);
int		ft_rotate(t_stack *stack);
int		ft_rrotate(t_stack *stack);

//lst aux
t_node	*ft_pop_node(t_stack *stack, t_node *node);
int		ft_push_back(t_stack *stack, t_node *node);
int		ft_push_front(t_stack *stack, t_node *node);

#endif