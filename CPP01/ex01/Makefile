# **************************************************************************** #
#                                                                              #
#                                                      ██   ██ ██████          #
#    Makefile                                          ██   ██      ██         #
#                                                      ███████  █████          #
#    By: maroy <maroy@student.42.qc>                        ██ ██              #
#                                                           ██ ███████.qc      #
#    Created: 2023/09/02 20:07:36 by maroy                                     #
#    Updated: 2023/10/26 13:55:48 by maroy            >(.)__ <(.)__ =(.)__     #
#                                                      (___/  (___/  (___/     #
# **************************************************************************** #

NAME = ex01

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -I$(INC_DIR)
CC = c++

# Directories
SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = ./
INC_DIR = inc

# Source files and object files
SRCS = $(shell find $(SRC_DIR) -iname "*.cpp")
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: directories $(BUILD_DIR)/$(NAME)
	@echo "$(GREEN)$(NAME) created !$(DEFAULT)"

# Debug target
debug: CPPFLAGS += -DDEBUG=1 -g
debug: re
	@echo "$(GREEN)$(NAME) created in debug mode !$(DEFAULT)"
	
# Create necessary directories
directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BUILD_DIR)

# Build the executable
$(BUILD_DIR)/$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $@

# Compile the source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo	"$(YELLOW)Obejct files deleted!$(DEFAULT)"

# Clean object files and the executable
fclean: clean
	@rm -rf $(BUILD_DIR)
	@echo	"$(RED)All deleted!$(DEFAULT)"

# Rebuild everything
re: fclean all

.PHONY: all directories clean fclean re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DARKGRAY= \033[1;30m
DEFAULT = \033[1;30m