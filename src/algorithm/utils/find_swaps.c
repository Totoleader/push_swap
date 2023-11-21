/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_swaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:06:24 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 13:47:01 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//checks if there is a good "a" swap in the first part of the algorithm
int	should_swap_a(t_list *curr_a, t_list *next_a)
{
	if (curr_a && next_a && curr_a->findex > next_a->findex
		&& curr_a->bucket == next_a->bucket)
		return (TRUE);
	return (FALSE);
}

//checks if there is a good "b" swap in the first part of the algorithm
int	should_swap_b(t_list *curr_b, t_list *next_b)
{
	if (curr_b && next_b && curr_b->findex < next_b->findex
		&& curr_b->bucket == next_b->bucket)
		return (TRUE);
	return (FALSE);
}

//checks if there is a good ss in the first part of the algorithm
int	should_double_swap(t_list *curr_a, t_list *curr_b, t_list *next_a,
		t_list *next_b)
{
	t_list	*next_next_a;

	next_next_a = NULL;
	if (next_a)
		next_next_a = next_a->next;
	if (((curr_a && next_a && curr_a->bucket - next_a->bucket >= -1
				&& curr_a->bucket - next_a->bucket <= -1)
			|| (should_swap_a(curr_a, next_a))) && should_swap_b(curr_b,
			next_b))
		return (TRUE);
	return (FALSE);
}

//looks for swaps int the first part of the algorithm
int	find_swaps(t_list **stack_a, t_list **stack_b)
{
	t_list	*next_a;
	t_list	*next_b;
	t_list	*current_a;
	t_list	*current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	next_a = NULL;
	next_b = NULL;
	if (current_a)
		next_a = current_a->next;
	if (current_b)
		next_b = current_b->next;
	if (should_double_swap(current_a, current_b, next_a, next_b)
		&& !does_create_hole(next_b))
		ss(stack_a, stack_b);
	else if (should_swap_a(current_a, next_a))
		swap('a', stack_a);
	else if (should_swap_b(current_b, next_b) && !does_create_hole(next_b))
		swap('b', stack_b);
	else
		return (0);
	return (1);
}
