# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvann <mvann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 14:11:42 by mvann             #+#    #+#              #
#    Updated: 2018/06/23 16:13:43 by mvann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
LIBFT = -L libft/ -lft
PUSH_SWAP = push_swap
CHECKER = checker
SRC = push_swap.c\
	swap.c\
	rotate.c\
	more_rotate.c\
	push.c\
	more_push.c\
	helper_funcs.c\
	more_helper_funcs.c\
	parse.c\
	small_algorithm.c
CHECKER_SRC = checker.c\
	swap.c\
	rotate.c\
	more_rotate.c\
	push.c\
	more_push.c\
	helper_funcs.c\
	more_helper_funcs.c\
	parse.c\
	small_algorithm.c
# PUSH_SWAP_SRC = push_swap.c
# 	$(SRC)
# CHECKER_SRC = checker.c
# 	$(SRC)

.PHONY: test library all clean fclean re

all: library $(PUSH_SWAP) $(CHECKER)

test:
	@rm checker
	@rm push_swap
	@gcc $(FLAGS) -o $(PUSH_SWAP) $(SRC) $(LIBFT)
	@gcc $(FLAGS) -o $(CHECKER) $(CHECKER_SRC) $(LIBFT)

library:
	@cd libft/ && make

$(PUSH_SWAP):
	@gcc $(FLAGS) -o $(PUSH_SWAP) $(SRC) $(LIBFT)

$(CHECKER):
	@gcc $(FLAGS) -o $(CHECKER) $(CHECKER_SRC) $(LIBFT)

clean:
	@rm -f $(SRC:.c=.o)
	@cd libft/ && make clean

fclean: clean
	@rm -f $(PUSH_SWAP)
	@rm -f $(CHECKER)
	@cd libft/ && make fclean

re: fclean all
