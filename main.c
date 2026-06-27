/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-luc <made-luc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 08:27:08 by fbachman          #+#    #+#             */
/*   Updated: 2026/06/27 14:26:52 by made-luc         ###   ########.fr       */
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

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    double  disorder;

    // 1. Parsing & Initialization (Your colleague's part)
    if (!ft_parse_and_populate(&a, argc, argv))
        return (ft_error());

    // 2. Measure disorder BEFORE any moves are made
    disorder = ft_compute_disorder(&a);
    // Depending on your subject requirements, you might need to print it here:
    // printf("Initial disorder: %f\n", disorder);

    // 3. Sorting execution (Your part)
    if (a.size == 2)
        ft_sa(&a);
    else if (a.size == 3)
        ft_sort_three(&a);
    else if (a.size == 4)
        ft_sort_four(&a, &b);
    else if (a.size == 5)
        ft_sort_five(&a, &b);
    else
        ft_big_sort(&a, &b); // What you will tackle next!

    // 4. Free memory and exit
    return (0);
}
