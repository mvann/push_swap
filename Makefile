# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvann <mvann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 14:11:42 by mvann             #+#    #+#              #
#    Updated: 2018/05/19 13:54:28 by mvann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
LIBFT = -L libft/ -lft
NAME = push_swap
CHECKER = checker
SRC = push_swap.c\
	swap.c\
	rotate.c\
	push.c\
	helper_funcs.c

.PHONY: test all clean fclean re

test:
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)

all: $(NAME)

$(NAME):
	@cd libft && make
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)

clean:
	@rm -f $(SRC:.c=.o)
	@cd libft/ && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft/ && make fclean

re: fclean all
