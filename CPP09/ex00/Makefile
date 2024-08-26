# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroy <maroy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/02 20:07:36 by maroy             #+#    #+#              #
#    Updated: 2024/08/26 01:11:31 by maroy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BTC

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -I$(INC_DIR)
CC = c++

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

# Source files and object files
SRCS = $(shell find $(SRC_DIR) -iname "*.cpp")
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(OBJ_DIR) $(NAME)

# Create necessary directories
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Build the executable
$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)$(NAME) created !$(DEFAULT)"

# Compile the source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

leak: CPPFLAGS += -g3
leak: re
	@leaks --atExit -- ./$(NAME)

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo	"$(YELLOW)Obejct files deleted!$(DEFAULT)"

# Clean object files and the executable
fclean: clean
	@rm -rf $(NAME)
	@echo	"$(RED)All deleted!$(DEFAULT)"

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re leak

RED = $(shell tput setaf 1)
GREEN = $(shell tput setaf 2)
YELLOW = $(shell tput setaf 3)
DARKGRAY = $(shell tput setaf 0)
DEFAULT = $(shell tput sgr0)
