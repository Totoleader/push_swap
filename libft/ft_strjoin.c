/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:12:45 by macote            #+#    #+#             */
/*   Updated: 2023/04/13 11:49:08 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, size_t s2_len)
{
	char	*return_string;
	size_t	i;
	size_t	j;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	return_string = malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!return_string)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
	{
		return_string[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		return_string[i++] = s2[j++];
	return_string[i] = '\0';
	if (s1)
		free(s1);
	return (return_string);
}
