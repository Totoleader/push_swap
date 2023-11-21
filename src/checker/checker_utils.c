/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:49:40 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 13:50:50 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//parse instruction from stdin
char	**get_instructions(void)
{
	char	buffer[1];
	int		read_check;
	char	*string;
	char	**instructions;

	string = NULL;
	read_check = read(STDIN_FILENO, buffer, 1);
	while (read_check > 0)
	{
		string = ft_strjoin(string, buffer, read_check);
		read_check = read(STDIN_FILENO, buffer, 1);
	}
	if (!string)
		string = ft_calloc(1, sizeof(char));
	instructions = ft_split(string, '\n');
	free(string);
	return (instructions);
}

//things to do when an instructions is found invalid
void	checker_error(char **instructions, t_list **stack_a, t_list **stack_b,
		int i)
{
	while (instructions[i])
	{
		free(instructions[i]);
		i++;
	}
	free(instructions);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	error();
}
