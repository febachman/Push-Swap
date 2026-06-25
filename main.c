/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 08:27:08 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/25 08:28:21 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack stack_a;
    int     *parsed_array;
    int     array_size;

    // 1. Safety first: Initialize your stack structure
    ft_init_stack(&stack_a);

    // 2. Your friend's parsing logic takes over
    // (This is an example of how they might have structured it)
    parsed_array = your_friends_parsing_function(argc, argv, &array_size);
    if (!parsed_array)
        return (1); // Handle parsing error

    // 3. Your initialization logic takes over
    populate_stack(&stack_a, parsed_array, array_size);

    // 4. Time to sort!
    // sort_small(&stack_a);

    // Don't forget to free the parsed_array and stack nodes before exiting!
    return (0);
}
