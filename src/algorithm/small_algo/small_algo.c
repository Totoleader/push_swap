/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:50:54 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 13:35:17 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//algo for 2 data
void	algo2(char c, t_list **stack)
{
	if (c == 'a' && (*stack)->findex > (*stack)->next->findex)
		swap('a', stack);
	else if (c == 'b' && (*stack)->findex < (*stack)->next->findex)
		swap('b', stack);
}

//algo for 3 data
void	algo3(t_list **stack_a, t_minmax minmax)
{
	if ((*stack_a)->findex == minmax.max)
		rotate('a', stack_a);
	else if ((*stack_a)->next->findex == minmax.max)
		reverse_rotate('a', stack_a);
	algo2('a', stack_a);
}

//algo for 4 data
void	algo4(t_list **stack_a, t_list **stack_b, t_minmax minmax)
{
	if ((*stack_a)->next->findex == minmax.min)
	{
		swap('a', stack_a);
		if (list_is_sorted(*stack_a))
			return ;
	}
	if (ft_lstlast(*stack_a)->findex == minmax.min)
	{
		reverse_rotate('a', stack_a);
		if (list_is_sorted(*stack_a))
			return ;
		push('b', stack_a, stack_b);
	}
	else
	{
		while ((*stack_a)->findex != minmax.min)
			rotate('a', stack_a);
		if (list_is_sorted(*stack_a))
			return ;
		push('b', stack_a, stack_b);
	}
	algo3(stack_a, minmax);
	push('a', stack_b, stack_a);
}

//algo for 5 data
void	algo5(t_list **stack_a, t_list **stack_b, t_minmax minmax)
{
	while (ft_lstsize(*stack_a) != 3)
	{
		if ((*stack_a)->findex <= minmax.min + 1)
			push('b', stack_a, stack_b);
		else
			rotate('a', stack_a);
	}
	algo3(stack_a, minmax);
	algo2('b', stack_b);
	push('a', stack_b, stack_a);
	push('a', stack_b, stack_a);
}

//controller for small algos
void	small_algos(t_list **stack_a, t_list **stack_b)
{
	t_minmax	minmax;
	int			lstsize;

	lstsize = ft_lstsize(*stack_a);
	find_minmax(&minmax.min, &minmax.max, *stack_a);
	if (lstsize == 2)
		algo2('a', stack_a);
	else if (lstsize == 3)
		algo3(stack_a, minmax);
	else if (lstsize == 4)
		algo4(stack_a, stack_b, minmax);
	else if (lstsize == 5)
		algo5(stack_a, stack_b, minmax);
}
