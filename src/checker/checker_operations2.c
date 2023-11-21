/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:20:36 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 13:08:16 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Operations in this file are the same as the operations in
// ../operations but they dont print anything
void	push_c(t_list **src, t_list **dest)
{
	t_list	*new_first;

	if (!src || !(*src))
		return ;
	new_first = (*src)->next;
	ft_lstadd_front(dest, (*src));
	*src = new_first;
}

void	swap_c(t_list **head)
{
	t_list	*second;

	if (!head || !(*head)->next)
		return ;
	second = (*head)->next;
	(*head)->next = second->next;
	second->next = *head;
	*head = second;
}

void	ss_c(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		swap('x', stack_a);
	if (*stack_b && (*stack_b)->next)
		swap('x', stack_b);
}
