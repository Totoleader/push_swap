/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:24:34 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 13:48:27 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//error
void	error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

//find minimum and maximum value in the stack
void	find_minmax(int *min, int *max, t_list *list)
{
	t_list	*current;

	current = list;
	*max = current->findex;
	*min = current->findex;
	while (current)
	{
		if (current->findex > *max)
			*max = current->findex;
		else if (current->findex < *min)
			*min = current->findex;
		current = current->next;
	}
}

//checks if list is sorted???
int	list_is_sorted(t_list *list)
{
	t_list	*current;
	t_list	*next;
	int		min;
	int		max;

	if (!list)
		return (1);
	find_minmax(&min, &max, list);
	current = list;
	next = list->next;
	while (next)
	{
		if (current->findex != next->findex - 1 && (current->findex != max
				|| next->findex != min))
			return (FALSE);
		current = current->next;
		next = current->next;
	}
	return (TRUE);
}

int	list_is_fully_sorted(t_list *list)
{
	t_list	*current;
	t_list	*next;

	if (!list)
		return (1);
	current = list;
	next = list->next;
	while (next)
	{
		if (current->content > next->content)
			return (FALSE);
		current = current->next;
		next = current->next;
	}
	return (TRUE);
}
