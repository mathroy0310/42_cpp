# **************************************************************************** #
#                                                                              #
#                                                      ██   ██ ██████          #
#    Makefile                                          ██   ██      ██         #
#                                                      ███████  █████          #
#    By: maroy <maroy@student.42.qc>                        ██ ██              #
#                                                           ██ ███████.qc      #
#    Created: 2023/09/02 20:07:36 by maroy                                     #
#    Updated: 2023/10/26 13:04:30 by maroy            >(.)__ <(.)__ =(.)__     #
#                                                      (___/  (___/  (___/     #
# **************************************************************************** #

NAME = ex02

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address
CC = c++

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Source files and object files
SRCS = $(shell find $(SRC_DIR) -iname "*.cpp")
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: directories $(NAME)
	@echo "$(GREEN)$(NAME) created !$(DEFAULT)"

# Create necessary directories
directories:
	@mkdir -p $(OBJ_DIR)

# Build the executable
$(NAME): $(OBJS)
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
	@rm -rf $(NAME)
	@echo	"$(RED)All deleted!$(DEFAULT)"

# Rebuild everything
re: fclean all

.PHONY: all directories clean fclean re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DARKGRAY= \033[1;30m
DEFAULT = \033[1;30m