/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:56:47 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 13:57:19 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate_top_helper(t_list **stack_a, t_list **stack_b,
		t_bucket_info *bucket)
{
	while (bucket->up_push_count)
	{
		if ((*stack_a)->bucket != bucket->bucket_down - 1
			&& ((*stack_a)->bucket != bucket->bucket_up)
			&& (*stack_a)->bucket != bucket->last_bucket)
			rr(stack_a, stack_b);
		else if ((*stack_a)->bucket != bucket->bucket_down - 1
			&& (*stack_a)->bucket == bucket->last_bucket)
		{
			rr(stack_a, stack_b);
			find_swaps_last_bucket(stack_a, stack_b);
			bucket->up_push_count--;
			continue ;
		}
		else
			rotate('b', stack_b);
		find_safe_swaps(stack_a, stack_b);
		bucket->up_push_count--;
	}
}

void	empty_top(t_list **stack_a, t_list **stack_b, t_bucket_info *bucket)
{
	t_list	*current;
	int		bucket_init;
	int		skip;

	skip = 0;
	if (*stack_b)
		bucket_init = (*stack_b)->bucket;
	current = NULL;
	if (*stack_b)
		current = (*stack_b)->next;
	while (current)
	{
		if (current->bucket != bucket_init)
			skip++;
		current = current->next;
	}
	if (!skip)
	{
		bucket->up_push_count = 0;
		return ;
	}
	rotate_top_helper(stack_a, stack_b, bucket);
}

void	empty_top2(t_list **stack_a, t_list **stack_b, t_bucket_info *bucket,
		int rots)
{
	while (rots--)
	{
		if (*stack_a && (*stack_a)->bucket == bucket->bucket_down
			&& ++bucket->in_da_bucket_down)
		{
			push('b', stack_a, stack_b);
			find_safe_swaps(stack_a, stack_b);
			rotate('b', stack_b);
		}
		else
		{
			rr(stack_a, stack_b);
			find_safe_swaps(stack_a, stack_b);
			bucket->up_push_count--;
		}
	}
	while (bucket->up_push_count)
	{
		rotate('b', stack_b);
		bucket->up_push_count--;
	}
}

void	rot_last_bucket(t_list **stack_a, t_list **stack_b,
		t_bucket_info bucket)
{
	while (bucket.up_push_count)
	{
		find_swaps(stack_a, stack_b);
		if (*stack_a && (((*stack_a)->bucket == bucket.bucket_up)
				|| ((*stack_a)->bucket == bucket.bucket_down)))
			rotate('b', stack_b);
		else
			rr(stack_a, stack_b);
		bucket.up_push_count--;
	}
}
