/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:43:43 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 13:47:10 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	find_safe_swaps(t_list **stack_a, t_list **stack_b)
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
	if (should_swap_a(current_a, next_a) && should_swap_b(current_b, next_b)
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

int	find_swaps_last_bucket(t_list **stack_a, t_list **stack_b)
{
	t_list	*next_a;
	t_list	*next_b;
	int		min;
	int		max;

	find_minmax(&min, &max, *stack_a);
	min = 0;
	next_a = NULL;
	next_b = NULL;
	if (*stack_a)
		next_a = (*stack_a)->next;
	if (*stack_b)
		next_b = (*stack_b)->next;
	if (should_swap_a(*stack_a, next_a) && (*stack_a)->findex != max
		&& should_swap_b(*stack_a, *stack_b))
		ss(stack_a, stack_b);
	else if (should_swap_a(*stack_a, next_a) && (*stack_a)->findex != max)
		swap('a', stack_a);
	else if (should_swap_b(*stack_a, *stack_b))
		swap('b', stack_b);
	else
		return (0);
	return (1);
}

int	does_create_hole(t_list *next_b)
{
	t_list	*next_next;

	if (!next_b)
		return (FALSE);
	next_next = next_b->next;
	if (!next_next)
		return (FALSE);
	if (next_b->findex - next_next->findex >= -1 && next_b->findex
		- next_next->findex <= 1)
		return (TRUE);
	return (FALSE);
}
