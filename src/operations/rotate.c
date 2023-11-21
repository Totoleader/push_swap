/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:48:44 by macote            #+#    #+#             */
/*   Updated: 2023/05/04 12:05:06 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//rotate a, rotate b
void	rotate(char c, t_list **head)
{
	t_list	*new_first;

	if (!head || !(*head) || !(*head)->next)
		return ;
	new_first = (*head)->next;
	ft_lstadd_back(head, *head);
	(*head)->next = NULL;
	*head = new_first;
	if (c == 'a')
		printf("ra\n");
	else if (c == 'b')
		printf("rb\n");
}

//reverse rotate a, reverse rotate b
void	reverse_rotate(char c, t_list **head)
{
	t_list	*new_last;

	if (!*head)
		return ;
	new_last = ft_second_lstlast(*head);
	ft_lstadd_front(head, ft_lstlast(*head));
	new_last->next = NULL;
	if (c == 'a')
		printf("rra\n");
	else if (c == 'b')
		printf("rrb\n");
}

//rotate a & b
void	rr(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		rotate('x', stack_a);
	if (stack_b)
		rotate('x', stack_b);
	printf("rr\n");
}

//reverse rotate a & b
void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		reverse_rotate('x', stack_a);
	if (stack_b)
		reverse_rotate('x', stack_b);
	printf("rrr\n");
}
