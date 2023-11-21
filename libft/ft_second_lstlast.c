/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_lstlast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:24:17 by macote            #+#    #+#             */
/*   Updated: 2023/05/09 10:58:32 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_second_lstlast(t_list *lst)
{
	t_list	*next;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	next = lst->next;
	while (next->next)
	{
		lst = lst->next;
		next = lst->next;
	}
	return (lst);
}
