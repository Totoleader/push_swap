/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:09:54 by macote            #+#    #+#             */
/*   Updated: 2023/05/30 15:35:30 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	assign_bucket(t_list **stack_a, int value_count, int bucket_size)
{
	t_list	*current;
	int		bucket_nb;
	int		middle_bucket;

	bucket_nb = (value_count / bucket_size) + 1;
	current = *stack_a;
	while (current)
	{
		current->bucket = current->findex / bucket_size;
		current = current->next;
	}
	middle_bucket = (bucket_nb / 2) - 1;
	return (middle_bucket);
}

void	init_bucket_vars(t_bucket_info *bucket, t_list **stack_a)
{
	bucket->value_count = ft_lstsize(*stack_a);
	bucket->bucket_size = 0.045 * bucket->value_count + 3.5;
	bucket->middle_bucket = assign_bucket(stack_a, bucket->value_count,
			(int)bucket->bucket_size);
	bucket->bucket_up = bucket->middle_bucket + 1;
	bucket->bucket_down = bucket->middle_bucket;
	bucket->in_da_bucket_up = 0;
	bucket->in_da_bucket_down = 0;
	bucket->up_push_count = 0;
	bucket->last_bucket = bucket->value_count / bucket->bucket_size - 1;
	if (bucket->value_count % bucket->bucket_size != 0)
		bucket->last_bucket++;
}

void	algo_controller(t_list **stack_a, t_list **stack_b)
{
	t_bucket_info	bucket;

	init_bucket_vars(&bucket, stack_a);
	if (list_is_fully_sorted(*stack_a))
		return ;
	if (bucket.value_count <= 5)
	{
		small_algos(stack_a, stack_b);
		return ;
	}
	to_b(stack_a, stack_b, bucket);
	launch_the_death_wheel(stack_a, stack_b, bucket);
}
