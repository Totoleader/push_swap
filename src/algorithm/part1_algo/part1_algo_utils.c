/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1_algo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:32:06 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 13:55:27 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//checks if the value in stack a is in the bucket on top of stack b
int	should_push_top(t_list *stack_a, t_bucket_info *bucket)
{
	if (stack_a && stack_a->bucket == bucket->bucket_up
		&& bucket->bucket_up != bucket->last_bucket
		&& ++bucket->in_da_bucket_up)
		return (TRUE);
	return (FALSE);
}

//checks if the value in stack a is in the bucket on bottom of stack b
int	should_push_bottom(t_list *stack_a, t_bucket_info *bucket)
{
	if (stack_a && stack_a->bucket == bucket->bucket_down
		&& ++bucket->in_da_bucket_down)
		return (TRUE);
	return (FALSE);
}

//checks if there is nothing to be pushed so that its ok to rr
int	should_rr_till_next_push(int rots, t_bucket_info *bucket)
{
	if (rots <= bucket->up_push_count && rots != 0
		&& bucket->bucket_up != bucket->last_bucket
		&& ++bucket->in_da_bucket_up)
		return (TRUE);
	return (FALSE);
}

int	all_the_same_bucket(t_list *stack_a)
{
	t_list	*current;
	t_list	*next;
	int		bucket;

	current = stack_a;
	bucket = current->bucket;
	while (current)
	{
		next = current->next;
		if (current->bucket != bucket || current->bucket == 0)
			return (FALSE);
		current = next;
	}
	return (TRUE);
}

int	rots_till_next_up_push(t_list *stack_a, t_bucket_info bucket)
{
	int	count;

	if (!stack_a)
		return (0);
	count = 0;
	while (stack_a && stack_a->bucket != bucket.bucket_up
		&& bucket.in_da_bucket_up <= bucket.last_bucket)
	{
		count++;
		stack_a = stack_a->next;
	}
	return (count);
}
