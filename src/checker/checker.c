/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:39:19 by macote            #+#    #+#             */
/*   Updated: 2023/05/16 13:50:10 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//finds operation based on the instruction list
int	find_instruction(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(instruction, "sa", 3))
		swap_c(stack_a);
	else if (!ft_strncmp(instruction, "sb", 3))
		swap_c(stack_b);
	else if (!ft_strncmp(instruction, "ss", 3))
		ss_c(stack_a, stack_b);
	else if (!ft_strncmp(instruction, "pa", 3))
		push_c(stack_b, stack_a);
	else if (!ft_strncmp(instruction, "pb", 3))
		push_c(stack_a, stack_b);
	else if (!ft_strncmp(instruction, "ra", 3))
		rotate_c(stack_a);
	else if (!ft_strncmp(instruction, "rb", 3))
		rotate_c(stack_b);
	else if (!ft_strncmp(instruction, "rra", 4))
		reverse_rotate_c(stack_a);
	else if (!ft_strncmp(instruction, "rrb", 4))
		reverse_rotate_c(stack_a);
	else if (!ft_strncmp(instruction, "rr", 3))
		rr_c(stack_a, stack_b);
	else if (!ft_strncmp(instruction, "rrr", 4))
		rrr_c(stack_a, stack_b);
	else
		return (0);
	return (1);
}

//does all operations
void	exec_instructions(char **instructions, t_list **stack_a,
		t_list **stack_b)
{
	int	i;

	i = 0;
	while (instructions[i])
	{
		if (!find_instruction(instructions[i], stack_a, stack_b))
			checker_error(instructions, stack_a, stack_b, i);
		free(instructions[i]);
		i++;
	}
	free(instructions);
}

//checker main function
void	checker(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**instructions;

	instructions = NULL;
	stack_a = NULL;
	stack_b = NULL;
	parse_numbers(argc, argv, &stack_a);
	instructions = get_instructions();
	exec_instructions(instructions, &stack_a, &stack_b);
	if (list_is_fully_sorted(stack_a) && !stack_b)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	checker(argc, argv);
	return (0);
}
