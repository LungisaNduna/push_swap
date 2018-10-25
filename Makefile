# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnduna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 13:35:08 by lnduna            #+#    #+#              #
#    Updated: 2018/09/03 12:28:23 by lnduna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

INC = ./inc/
HEADER = ./inc/push_swap.h

COMP = gcc -Wall -Wextra -Werror

all: $(NAME) $(NAME2)

$(NAME): $(HEADER) myLib
	@gcc -Wall -Wextra -Werror -o $(NAME) -I./inc/ src/* $(NAME).c libft/libft.a
	@echo "$(NAME) is ready to use."

$(NAME2): $(HEADER) myLib
	@gcc -Wall -Wextra -Werror -o $(NAME2) -I./inc/ src/* $(NAME2).c libft/libft.a
	@echo "$(NAME2) is ready to use."

myLib:
	@make -C ./libft/

clean:
	@make fclean -C ./libft/
	@echo "the extra stuff has been removed"

fclean: clean
	@rm $(NAME) $(NAME2)
	@echo "$(NAME) and $(NAME2) have been removed"

re: fclean all
