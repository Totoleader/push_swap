/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_things_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:53 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 15:09:56 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pushhh(t_list **stack_a, t_list **stack_b, int *i, int *pushed)
{
	push('a', stack_b, stack_a);
	*pushed = TRUE;
	(*i)++;
}

void	push_and_swap(t_list **stack_a, t_list **stack_b, int *i, int *pushed)
{
	push('a', stack_b, stack_a);
	swap('a', stack_a);
	*pushed = TRUE;
	(*i)++;
}

void	swap_and_push(t_list **stack_a, t_list **stack_b, int *i, int *pushed)
{
	swap('b', stack_b);
	push('a', stack_b, stack_a);
	*pushed = TRUE;
	(*i)++;
}

void	rotate_till_placed(t_list **stack_a, t_list **stack_b, int *i, int *j)
{
	rot_till_placed(stack_a, stack_b, j);
	(*i)++;
}

void	rot_swap_push(t_list **stack_a, t_list **stack_b, int *i)
{
	rotate('b', stack_b);
	swap('b', stack_b);
	push('a', stack_b, stack_a);
	if (*stack_b && should_place_now(*stack_a, *stack_b))
	{
		push('a', stack_b, stack_a);
		(*i)++;
	}
	else if (should_push_and_swap(*stack_a, *stack_b))
	{
		push('a', stack_b, stack_a);
		swap('a', stack_a);
		(*i)++;
	}
	(*i)++;
}
