/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:35:11 by macote            #+#    #+#             */
/*   Updated: 2023/05/18 11:11:38 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//input error catching helper
static void	check_value(long long value, int *i)
{
	if ((value > INT_MAX || value < INT_MIN) && *i >= 0)
		*i = -1;
}

//input error catching helper
static void	check_error(int i, t_list **stack_a)
{
	if (i < 0)
	{
		ft_lstclear(stack_a);
		error();
	}
}

void	malloc_error(char **args_array, t_list **stack_a, int j)
{
	free(args_array[j]);
	free(args_array);
	ft_lstclear(stack_a);
	error();
}

//returns an error if there are doubled values
void	check_doubles(t_list *stack_a)
{
	t_list	*current;
	t_list	*compare;

	current = stack_a;
	while (current && current->next)
	{
		compare = current->next;
		while (compare)
		{
			if (current->content == compare->content)
			{
				ft_lstclear(&stack_a);
				error();
			}
			compare = compare->next;
		}
		current = current->next;
	}
}

//main parsing function that splits args and puts values into lists
void	parse_numbers(int argc, char **argv, t_list **stack_a)
{
	char		**args_array;
	int			i;
	int			j;
	long long	value;

	i = 0;
	while (i < argc - 1)
	{
		args_array = ft_split(argv[i + 1], ' ');
		j = 0;
		while (args_array[j])
		{
			value = ft_atoi((args_array)[j]);
			if (!ft_lstadd_back(stack_a, ft_lstnew((int)value, 0, 0)))
				malloc_error(args_array, stack_a, j);
			free(args_array[j++]);
			check_value(value, &i);
		}
		free(args_array);
		check_error(i, stack_a);
		i++;
	}
	check_doubles(*stack_a);
}
