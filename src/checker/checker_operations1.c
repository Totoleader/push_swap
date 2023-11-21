/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:18:41 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 13:07:55 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Operations in this file are the same as the operations in 
// ../operations but they dont print anything
void	rotate_c(t_list **head)
{
	t_list	*new_first;

	if (!head || !(*head) || !(*head)->next)
		return ;
	new_first = (*head)->next;
	ft_lstadd_back(head, *head);
	(*head)->next = NULL;
	*head = new_first;
}

void	reverse_rotate_c(t_list **head)
{
	t_list	*new_last;

	if (!*head)
		return ;
	new_last = ft_second_lstlast(*head);
	ft_lstadd_front(head, ft_lstlast(*head));
	new_last->next = NULL;
}

void	rr_c(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		rotate_c(stack_a);
	if (stack_b)
		rotate_c(stack_b);
}

void	rrr_c(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		reverse_rotate_c(stack_a);
	if (stack_b)
		reverse_rotate_c(stack_b);
}
