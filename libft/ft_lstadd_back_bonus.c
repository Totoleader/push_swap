/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:43:29 by macote            #+#    #+#             */
/*   Updated: 2023/05/17 10:44:26 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return (NULL);
	if (!(*lst))
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
	return (new);
}
