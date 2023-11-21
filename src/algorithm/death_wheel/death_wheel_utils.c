/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_wheel_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:24:19 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 13:40:21 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	last_isnt_ok(char c, t_list **stack)
{
	int		last_findex;
	int		last_bucket;
	t_list	*current;

	if (!stack || !*stack)
		return (0);
	current = *stack;
	last_findex = 0;
	last_findex = ft_lstlast(*stack)->findex;
	last_bucket = ft_lstlast(*stack)->bucket;
	while (current->next && c == 'a')
	{
		if (current->findex > last_findex)
			return (TRUE);
		current = current->next;
	}
	current = *stack;
	while (current->next && c == 'b')
	{
		if (current->bucket < last_bucket)
			return (TRUE);
		current = current->next;
	}
	return (FALSE);
}

int	did_i_just_bust_my_b(t_list *stack_b)
{
	int		first_bucket;
	t_list	*current;

	current = stack_b;
	first_bucket = current->bucket;
	while (current)
	{
		if (current->bucket > first_bucket)
			return (TRUE);
		current = current->next;
	}
	return (FALSE);
}
