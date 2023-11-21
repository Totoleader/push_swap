/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_conditions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:06:53 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 15:10:03 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//helper conditions for "rotate_till_placed in part2_algo.c"
int	rtp_should_push(t_list **stack_a, t_list **stack_b)
{
	if (should_place(*stack_a, *stack_b)
		|| ((*stack_b)->findex < (*stack_a)->findex
			&& (*stack_b)->findex > ft_lstlast(*stack_a)->findex))
		return (TRUE);
	return (FALSE);
}

int	rtp_should_push_swap(t_list **stack_a, t_list **stack_b)
{
	if (should_push_and_swap(*stack_a, *stack_b)
		&& (*stack_b)->findex > (*stack_b)->next->findex)
		return (TRUE);
	return (FALSE);
}

int	rtp_should_swap_push(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_b) && (*stack_b)->next && (should_place_now(*stack_a,
				(*stack_b)->next))
		&& (*stack_b)->next->findex > (*stack_b)->findex)
		return (TRUE);
	return (FALSE);
}
