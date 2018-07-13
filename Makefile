# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/13 18:42:33 by rsibiet           #+#    #+#              #
#    Updated: 2017/02/13 18:42:37 by rsibiet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rsibiet.filler

FTC = 	main.c \
		define_next_position.c \
		isole_advers.c \
		go_to_updown.c \

FTO = $(subst .c,.o,$(FTC))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@echo ""
	@echo ""
	@echo "\033[32m• $(NAME) created!\033[0m"
	@echo "\n"
	@echo "\033[34;1m___________________________ Loading libft ______________________________\033[0m\n"
	@make -C ./libft
	@gcc -o $(NAME) -Wall -Wextra -Werror $(FTO) ./libft/libft.a -ltermcap
#	@gcc -o $(NAME) -Wall -Wextra -Werror -fsanitize=address -g3 $(FTO) ./libft/libft.a -ltermcap

%.o: %.c
#	@gcc -Wall -Wextra -Werror -fsanitize=address -g3 -I./libft/ -c $<
	@gcc -Wall -Wextra -Werror -I./libft/ -c $<
	@echo "\033[42m         \033[0m\c"

clean:
	@make -C ./libft clean
	@rm -rf $(FTO)
	@echo "\033[33m• $(NAME) object deleted!\033[0m"

fclean: clean
	@make -C ./libft fcleana
	@rm -rf $(NAME)
	@echo "\033[31;1m• \033[31m$(NAME) deleted!\033[0m"

re: fclean all
