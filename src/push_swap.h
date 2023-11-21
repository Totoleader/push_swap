/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:09:54 by macote            #+#    #+#             */
/*   Updated: 2023/05/18 11:32:44 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <libc.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

typedef struct push_swap
{
	int	in_da_bucket_up;
	int	in_da_bucket_down;
	int	bucket_up;
	int	bucket_down;
	int	up_push_count;
	int	something_pushed;
	int	middle_bucket;
	int	value_count;
	int	bucket_size;
	int	last_bucket;
}		t_bucket_info;

typedef struct push_swap2
{
	int	min;
	int	max;
}		t_minmax;

void	parse_numbers(int argc, char **argv, t_list **stack_a);

void	pre_sort(t_list *current);

void	push(char c, t_list **src, t_list **dest);
void	swap(char c, t_list **head);
void	ss(t_list **stack_a, t_list **stack_b);
void	rotate(char c, t_list **head);
void	reverse_rotate(char c, t_list **head);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	push_c(t_list **src, t_list **dest);
void	swap_c(t_list **head);
void	ss_c(t_list **stack_a, t_list **stack_b);
void	rotate_c(t_list **head);
void	reverse_rotate_c(t_list **head);
void	rr_c(t_list **stack_a, t_list **stack_b);
void	rrr_c(t_list **stack_a, t_list **stack_b);

void	error(void);

void	algo_controller(t_list **stack_a, t_list **stack_b);

int		should_double_swap(t_list *curr_a, t_list *curr_b, t_list *next_a,
			t_list *next_b);
int		should_swap_a(t_list *curr_a, t_list *next_a);
int		should_swap_b(t_list *curr_b, t_list *next_b);
int		find_swaps(t_list **stack_a, t_list **stack_b);
int		find_safe_swaps(t_list **stack_a, t_list **stack_b);
int		find_swaps2(t_list **stack_a, t_list **stack_b);
int		should_swap_a2(t_list *curr_a, t_list *next_a);
int		should_swap_b2(t_list *curr_b, t_list *next_b);
int		should_double_swap2(t_list *curr_a, t_list *curr_b, t_list *next_a,
			t_list *next_b);
int		find_swaps_last_bucket(t_list **stack_a, t_list **stack_b);
void	find_minmax(int *min, int *max, t_list *list);
int		list_is_fully_sorted(t_list *list);

void	launch_the_death_wheel(t_list **stack_a, t_list **stack_b,
			t_bucket_info bucket);

int		assign_bucket(t_list **stack_a, int value_count, int bucket_size);

int		list_is_sorted(t_list *list);

void	algo2(char c, t_list **stack);
void	algo3(t_list **stack_a, t_minmax minmax);
void	algo4(t_list **stack_a, t_list **stack_b, t_minmax minmax);
void	algo5(t_list **stack_a, t_list **stack_b, t_minmax minmax);
void	small_algos(t_list **stack_a, t_list **stack_b);

void	push_bucket(t_list **stack_a, t_list **stack_b, int bucket_size);
void	place_on_the_way_back(t_list **stack_a, t_list **stack_b, int *j,
			int *i);
void	rot_till_placed(t_list **stack_a, t_list **stack_b, int *j);

int		should_place(t_list *stack_a, t_list *stack_b);
int		should_push_and_swap(t_list *stack_a, t_list *stack_b);
int		should_place_now(t_list *stack_a, t_list *stack_b);
int		should_go_back(t_list *stack_a, t_list *stack_b);

void	wheel_it_up(t_list **stack_a, t_list **stack_b, int lstsize);
void	to_b(t_list **stack_a, t_list **stack_b, t_bucket_info bucket);

int		last_isnt_ok(char c, t_list **stack);
int		did_i_just_bust_my_b(t_list *stack_b);
int		does_create_hole(t_list *next_b);

int		should_push_top(t_list *stack_a, t_bucket_info *bucket);
int		should_push_bottom(t_list *stack_a, t_bucket_info *bucket);
int		should_rr_till_next_push(int rots, t_bucket_info *bucket);

char	**get_instructions(void);
void	checker_error(char **instructions, t_list **stack_a, t_list **stack_b,
			int i);
int		all_the_same_bucket(t_list *stack_a);
int		rots_till_next_up_push(t_list *stack_a, t_bucket_info bucket);

void	rotate_top_helper(t_list **stack_a, t_list **stack_b,
			t_bucket_info *bucket);
void	empty_top(t_list **stack_a, t_list **stack_b, t_bucket_info *bucket);
void	empty_top2(t_list **stack_a, t_list **stack_b, t_bucket_info *bucket,
			int rots);
void	rot_last_bucket(t_list **stack_a, t_list **stack_b,
			t_bucket_info bucket);
void	find_stupid_swap(t_list **stack_a, t_list **stack_b);

void	swap_and_push(t_list **stack_a, t_list **stack_b, int *i, int *pushed);
void	push_and_swap(t_list **stack_a, t_list **stack_b, int *i, int *pushed);
void	pushhh(t_list **stack_a, t_list **stack_b, int *i, int *pushed);
int		should_push_at_end(t_list **stack_a, t_list **stack_b);
int		should_rot_swap_push(t_list **stack_a, t_list **stack_b);
int		should_swap_and_push(t_list **stack_a, t_list **stack_b);
void	rotate_till_placed(t_list **stack_a, t_list **stack_b, int *i, int *j);
void	rot_swap_push(t_list **stack_a, t_list **stack_b, int *i);

int		rtp_should_swap_push(t_list **stack_a, t_list **stack_b);
int		rtp_should_push_swap(t_list **stack_a, t_list **stack_b);
int		rtp_should_push(t_list **stack_a, t_list **stack_b);
int		should_swap_push_swap(t_list **stack_a, t_list **stack_b);
void	swap_push_swap(t_list **stack_a, t_list **stack_b, int *i, int *pushed);

#endif
