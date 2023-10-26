# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroy <maroy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 22:23:58 by maroy             #+#    #+#              #
#    Updated: 2023/10/24 22:23:59 by maroy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

SRC = megaphone.cpp

OBJS = $(patsubst $(SRC)%.cpp,obj/%.o,$(SRC))

CC = g++

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -std=c++98

obj/%.o: $(SRC)%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created !$(DEFAULT)"

all: $(NAME)

clean:
			@$(RM) ./obj
			@echo	"$(YELLOW)Obejct files deleted!$(DEFAULT)"

fclean:		clean
			@$(RM) $(NAME)
			@echo	"$(RED)All deleted!$(DEFAULT)"  

re:			fclean all

.PHONY: all re clean fclean

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DARKGRAY= \033[1;30m
DEFAULT = \033[1;30m