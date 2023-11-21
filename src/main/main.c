/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:31:36 by macote            #+#    #+#             */
/*   Updated: 2023/05/08 15:01:24 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// PARSE TO LINKED LISTS, PRE-SORT, DO ALGO
void	push_swap(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	parse_numbers(argc, argv, &stack_a);
	pre_sort(stack_a);
	algo_controller(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
}

//main
int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	push_swap(argc, argv);
	return (0);
}
