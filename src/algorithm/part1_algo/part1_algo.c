/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:59:06 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 13:56:45 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	find_action(t_list **stack_a, t_list **stack_b, t_bucket_info *bucket,
		int rots)
{
	if (should_push_top(*stack_a, bucket))
	{
		empty_top(stack_a, stack_b, bucket);
		push('b', stack_a, stack_b);
		bucket->something_pushed = TRUE;
		find_swaps(stack_a, stack_b);
	}
	else if (should_push_bottom(*stack_a, bucket))
	{
		push('b', stack_a, stack_b);
		bucket->something_pushed = TRUE;
		bucket->up_push_count++;
		find_swaps(stack_a, stack_b);
	}
	else if (should_rr_till_next_push(rots, bucket))
	{
		empty_top2(stack_a, stack_b, bucket, rots);
		push('b', stack_a, stack_b);
		bucket->something_pushed = TRUE;
		find_swaps(stack_a, stack_b);
	}
}

void	check_for_bucket_switch(t_list **stack_a, t_list **stack_b,
		t_bucket_info *bucket)
{
	if (bucket->in_da_bucket_up == bucket->bucket_size && ++bucket->bucket_up)
		bucket->in_da_bucket_up = 0;
	if (bucket->in_da_bucket_down == bucket->bucket_size
		&& bucket->bucket_down--)
	{
		bucket->in_da_bucket_down = 0;
		empty_top(stack_a, stack_b, bucket);
	}
}

void	to_b(t_list **stack_a, t_list **stack_b, t_bucket_info bucket)
{
	int	rots;

	while (*stack_a && !all_the_same_bucket(*stack_a))
	{
		bucket.something_pushed = TRUE;
		while (*stack_a && bucket.something_pushed)
		{
			if (*stack_a && list_is_sorted(*stack_a)
				&& all_the_same_bucket(*stack_a))
			{
				rot_last_bucket(stack_a, stack_b, bucket);
				return ;
			}
			find_swaps(stack_a, stack_b);
			bucket.something_pushed = FALSE;
			bucket.value_count = ft_lstsize(*stack_a);
			rots = rots_till_next_up_push(*stack_a, bucket);
			find_action(stack_a, stack_b, &bucket, rots);
			check_for_bucket_switch(stack_a, stack_b, &bucket);
		}
		rotate('a', stack_a);
	}
	rot_last_bucket(stack_a, stack_b, bucket);
}
