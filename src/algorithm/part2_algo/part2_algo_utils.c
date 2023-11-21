/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2_algo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:54:43 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 14:03:54 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//checks if the node in b should be placed even if its not in the perfect spot
int	should_place(t_list *stack_a, t_list *stack_b)
{
	if (stack_b && stack_a && stack_b->findex > stack_a->findex)
		return (FALSE);
	return (TRUE);
}

//checks if the node in b is 1 off to be perfectly pushed to a
int	should_push_and_swap(t_list *stack_a, t_list *stack_b)
{
	if (stack_b && stack_b->next && stack_a
		&& stack_b->findex == stack_a->findex + 1
		&& stack_b->findex > stack_b->next->findex && stack_b->findex
		- stack_b->next->findex <= -1 && stack_b->findex
		- stack_b->next->findex >= 1)
		return (TRUE);
	return (FALSE);
}

//checks if the node in b can be perfectly pushed to a
int	should_place_now(t_list *stack_a, t_list *stack_b)
{
	if (stack_b && stack_a && stack_b->findex == stack_a->findex - 1)
		return (TRUE);
	return (FALSE);
}

//checks if the data in b should rotate the other way to be placed
int	should_go_back(t_list *stack_a, t_list *stack_b)
{
	if (stack_b && stack_a && stack_b->findex > stack_a->findex + 1)
		return (TRUE);
	return (FALSE);
}

void	find_stupid_swap(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_b) && (*stack_b)->next && (*stack_b)->next->next
		&& ((*stack_b)->findex == (*stack_b)->next->findex - 1
			&& !should_place_now(*stack_a, (*stack_b)))
		&& (*stack_b)->findex < (*stack_b)->next->findex)
		swap('b', stack_b);
}
