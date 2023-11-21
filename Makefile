# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macote <macote@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 10:34:58 by macote            #+#    #+#              #
#    Updated: 2023/05/18 11:41:54 by macote           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
NAME_BONUS	:= checker
CFLAGS	:= -Wall -Wextra -Werror -g

HEADERS	:= -I ./include
LIBFT 	:= ./libft
LIBS 	:= $(LIBFT)/libft.a

SRCS	:= src/main/main.c \

SRCS_COMMON	:= src/parsing/parse.c \
			src/pre_sort/pre_sort.c \
			src/operations/swap_push.c \
			src/operations/rotate.c \
			src/utils/utils.c \
			src/algorithm/part1_algo/part1_algo.c \
			src/algorithm/part1_algo/part1_algo2.c \
			src/algorithm/part1_algo/part1_algo_utils.c \
			src/algorithm/part2_algo/part2_algo.c \
			src/algorithm/part2_algo/rtp_conditions.c \
			src/algorithm/part2_algo/push_things_actions.c \
			src/algorithm/part2_algo/push_things_conditions.c \
			src/algorithm/part2_algo/part2_algo_utils.c \
			src/algorithm/utils/find_swaps.c \
			src/algorithm/utils/find_swaps2.c \
			src/algorithm/utils/other_utils.c \
			src/algorithm/death_wheel/death_wheel.c \
			src/algorithm/death_wheel/death_wheel_utils.c \
			src/algorithm/small_algo/small_algo.c \
			src/algorithm/algo_controller/algo_controller.c \
			
SRCS_BONUS := src/checker/checker.c \
				src/checker/checker_utils.c \
				src/checker/checker_operations1.c \
				src/checker/checker_operations2.c \

OBJS	:= ${SRCS:.c=.o} ${SRCS_COMMON:.c=.o}
OBJS_BONUS	:= ${SRCS_BONUS:.c=.o} ${SRCS_COMMON:.c=.o}

all: lib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

lib:
	@make -C $(LIBFT) all
	
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) $(CFLAGS) && printf "Compiled.\n"

bonus: $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS) $(CFLAGS) && printf "Compiled checker.\n"

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@rm -f $(OBJSLIB)
	@rm -f $(LIBS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make fclean -C libft && printf "Cleaned.\n"

re: clean all

.PHONY: all, clean, fclean, re