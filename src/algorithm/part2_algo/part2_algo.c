/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:51:32 by macote            #+#    #+#             */
/*   Updated: 2023/05/18 13:45:39 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//rotates stack a untill the right time to push to a
void	rot_till_placed(t_list **stack_a, t_list **stack_b, int *j)
{
	find_stupid_swap(stack_a, stack_b);
	while (TRUE)
	{
		if (rtp_should_push(stack_a, stack_b))
		{
			push('a', stack_b, stack_a);
			break ;
		}
		else if (rtp_should_push_swap(stack_a, stack_b))
		{
			push('a', stack_b, stack_a);
			swap('a', stack_a);
			break ;
		}
		else if (rtp_should_swap_push(stack_a, stack_b))
		{
			swap('b', stack_b);
			push('a', stack_b, stack_a);
			break ;
		}
		rotate('a', stack_a);
		(*j)++;
	}
}

int	push_things(t_list **stack_a, t_list **stack_b, int *j, int *i)
{
	int	pushed;

	pushed = TRUE;
	while (pushed)
	{
		pushed = FALSE;
		find_stupid_swap(stack_a, stack_b);
		if (should_place_now(*stack_a, *stack_b))
			pushhh(stack_a, stack_b, i, &pushed);
		else if (should_swap_push_swap(stack_a, stack_b))
			swap_push_swap(stack_a, stack_b, i, &pushed);
		else if (should_swap_and_push(stack_a, stack_b))
			swap_and_push(stack_a, stack_b, i, &pushed);
		else if (should_push_and_swap(*stack_a, *stack_b))
			push_and_swap(stack_a, stack_b, i, &pushed);
		else if (should_go_back(*stack_a, *stack_b) && ++pushed)
			rotate_till_placed(stack_a, stack_b, i, j);
		else if (should_push_at_end(stack_a, stack_b))
			pushhh(stack_a, stack_b, i, &pushed);
		else if (should_rot_swap_push(stack_a, stack_b))
			return (rot_swap_push(stack_a, stack_b, i), 1);
		find_stupid_swap(stack_a, stack_b);
	}
	return (0);
}

//returns to the beginning of stack a and checks
// for others pushes on the way back
void	place_on_the_way_back(t_list **stack_a, t_list **stack_b, int *j,
		int *i)
{
	while (*j)
	{
		find_stupid_swap(stack_a, stack_b);
		if (push_things(stack_a, stack_b, j, i))
			rrr(stack_a, stack_b);
		else
			reverse_rotate('a', stack_a);
		(*j)--;
	}
}

//pushes all elements of a bucket to a and places them at the right spot
void	push_bucket(t_list **stack_a, t_list **stack_b, int bucket_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < bucket_size)
	{
		rot_till_placed(stack_a, stack_b, &j);
		place_on_the_way_back(stack_a, stack_b, &j, &i);
	}
}

//main function of the second part of the algo
//pushes and sorts one bucket at a time
void	launch_the_death_wheel(t_list **stack_a, t_list **stack_b,
		t_bucket_info bucket)
{
	int	elem_count_init;
	int	elem_count;
	int	first_bucket_size;

	elem_count_init = ft_lstsize(*stack_b) + ft_lstsize(*stack_a);
	first_bucket_size = elem_count_init % bucket.bucket_size;
	elem_count = elem_count_init - first_bucket_size;
	if (first_bucket_size == 0)
		first_bucket_size = bucket.bucket_size;
	if (first_bucket_size <= 5)
		small_algos(stack_a, stack_b);
	else
		wheel_it_up(stack_a, stack_b, first_bucket_size);
	while (elem_count > 0)
	{
		push_bucket(stack_a, stack_b, bucket.bucket_size);
		elem_count -= bucket.bucket_size;
	}
}
