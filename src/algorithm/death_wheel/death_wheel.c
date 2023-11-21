/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_wheel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:10:44 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 13:39:26 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	end_the_wheel(t_list **stack_a, t_list **stack_b)
{
	while (last_isnt_ok('b', stack_b) && last_isnt_ok('a', stack_a))
	{
		rrr(stack_a, stack_b);
		find_swaps2(stack_a, stack_b);
	}
	while (last_isnt_ok('b', stack_b))
	{
		reverse_rotate('b', stack_b);
		find_swaps2(stack_a, stack_b);
	}
	while (*stack_b && did_i_just_bust_my_b(*stack_b))
	{
		rotate('b', stack_b);
		find_swaps2(stack_a, stack_b);
	}
	while (last_isnt_ok('a', stack_a))
	{
		reverse_rotate('a', stack_a);
	}
}

void	death_swap(t_list **stack_a, t_list **stack_b, void (*rot)(char,
			t_list **), void (*rot_rot)(t_list **stack_a, t_list **stack_b),
		int *i)
{
	t_list	*next_b;

	if (!(*stack_b))
		next_b = NULL;
	else
		next_b = (*stack_b)->next;
	if (*stack_a && should_double_swap2(*stack_a, *stack_b, (*stack_a)->next,
			next_b))
		ss(stack_a, stack_b);
	else if (*stack_a && should_swap_a2(*stack_a, (*stack_a)->next))
		swap('a', stack_a);
	else if (*stack_b && should_swap_b2(*stack_b, (*stack_b)->next) && ++(*i))
		rot('a', stack_a);
	else
	{
		rot_rot(stack_a, stack_b);
		(*i)++;
	}
}

//primitive nonsense that is a backup in certain cases (lol)
void	wheel_it_up(t_list **stack_a, t_list **stack_b, int lstsize)
{
	int		i;
	void	(*rot)(char, t_list**);
	void	(*rot_rot)(t_list **stack_a, t_list **stack_b);

	rot = &rotate;
	rot_rot = &rr;
	i = 0;
	while (!list_is_sorted(*stack_a))
	{
		if (((i == lstsize - 2) && rot == &reverse_rotate))
		{
			rot = &rotate;
			rot_rot = &rr;
			i = 0;
		}
		else if ((i == lstsize - 2) && rot == &rotate)
		{
			rot = &reverse_rotate;
			rot_rot = &rrr;
			i = 0;
		}
		death_swap(stack_a, stack_b, rot, rot_rot, &i);
	}
	end_the_wheel(stack_a, stack_b);
}
