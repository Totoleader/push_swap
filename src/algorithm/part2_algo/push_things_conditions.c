/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_things_conditions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:50:29 by macote            #+#    #+#             */
/*   Updated: 2023/05/18 11:35:39 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	should_push_at_end(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a) && (*stack_b) && ((should_place(*stack_a, *stack_b)
				|| ((*stack_b)->findex < (*stack_a)->findex
					&& (*stack_b)->findex > ft_lstlast(*stack_a)->findex))
			&& ft_lstlast(*stack_a)->findex < (*stack_b)->findex))
		return (TRUE);
	return (FALSE);
}

int	should_rot_swap_push(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_b) && (*stack_b)->next && (*stack_b)->next
		&& should_place_now(*stack_a, (*stack_b)->next->next))
		return (TRUE);
	return (FALSE);
}

int	should_swap_and_push(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_b) && (*stack_b)->next && should_place_now(*stack_a,
			(*stack_b)->next))
		return (TRUE);
	return (FALSE);
}

int	should_swap_push_swap(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next
		&& should_place_now((*stack_a)->next, (*stack_b)->next))
		return (1);
	return (0);
}

void	swap_push_swap(t_list **stack_a, t_list **stack_b, int *i, int *pushed)
{
	swap('b', stack_b);
	push('a', stack_b, stack_a);
	swap('a', stack_a);
	*pushed = TRUE;
	(*i)++;
}
