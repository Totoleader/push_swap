/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_swaps2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:42:27 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 13:44:16 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//checks if there is a good "a" swap in the second part of the algorithm
int	should_swap_a2(t_list *curr_a, t_list *next_a)
{
	if (next_a && curr_a && ((curr_a->findex > next_a->findex && curr_a->bucket
				- next_a->bucket >= -1 && curr_a->bucket
				- next_a->bucket <= 1)))
		return (TRUE);
	return (FALSE);
}

//checks if there is a good "b" swap in the second part of the algorithm
int	should_swap_b2(t_list *curr_b, t_list *next_b)
{
	if (curr_b && next_b && curr_b->findex < next_b->findex && curr_b->bucket
		- next_b->bucket >= -1 && curr_b->bucket - next_b->bucket <= 1)
		return (TRUE);
	return (FALSE);
}

//checks if there is a good ss in the second part of the algorithm
int	should_double_swap2(t_list *curr_a, t_list *curr_b, t_list *next_a,
		t_list *next_b)
{
	t_list	*next_next_a;

	next_next_a = NULL;
	if (next_a)
		next_next_a = next_a->next;
	if ((should_swap_a2(curr_a, next_a) && should_swap_b2(curr_b, next_b))
		|| (should_swap_a2(curr_a, next_a) && !curr_b)
		|| (should_swap_b2(curr_b, next_b) && !curr_a))
		return (TRUE);
	return (FALSE);
}

//looks for swaps int the second part of the algorithm
int	find_swaps2(t_list **stack_a, t_list **stack_b)
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
	if (should_double_swap2(current_a, current_b, next_a, next_b))
		ss(stack_a, stack_b);
	else if (should_swap_a2(current_a, next_a))
		swap('a', stack_a);
	else if (should_swap_b2(current_b, next_b))
		swap('b', stack_b);
	else
		return (0);
	return (1);
}
