/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:00:09 by macote            #+#    #+#             */
/*   Updated: 2023/05/04 11:59:24 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//if() helper
static int	should_increment(t_list *current, t_list *compare)
{
	if (current->content > compare->content)
		return (TRUE);
	return (FALSE);
}

//Main pre-sorting function that finds where 
//each node should be at the end (findex).
void	pre_sort(t_list *head)
{
	t_list	*current;
	t_list	*compare;

	current = head;
	while (current)
	{
		compare = head;
		while (compare)
		{
			if (should_increment(current, compare))
			{
				current->findex++;
			}
			compare = compare->next;
		}
		current = current->next;
	}
}
