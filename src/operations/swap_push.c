/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:42:19 by macote            #+#    #+#             */
/*   Updated: 2023/05/04 12:05:42 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//push a, push b
void	push(char c, t_list **src, t_list **dest)
{
	t_list	*new_first;

	if (!src || !(*src))
		return ;
	new_first = (*src)->next;
	ft_lstadd_front(dest, (*src));
	*src = new_first;
	if (c == 'a')
		printf("pa\n");
	else if (c == 'b')
		printf("pb\n");
}

//swap a, swap b
void	swap(char c, t_list **head)
{
	t_list	*second;

	if (!head || !(*head)->next)
		return ;
	second = (*head)->next;
	(*head)->next = second->next;
	second->next = *head;
	*head = second;
	if (c == 'a')
		printf("sa\n");
	else if (c == 'b')
		printf("sb\n");
}

//swap a & b
void	ss(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		swap('x', stack_a);
	if (*stack_b && (*stack_b)->next)
		swap('x', stack_b);
	printf("ss\n");
}
