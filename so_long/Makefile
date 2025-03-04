# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 11:44:30 by abeaufil          #+#    #+#              #
#    Updated: 2025/02/28 10:42:34 by abeaufil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
CYAN    = \033[36m
RESET   = \033[0m

NAME	= so_long
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I./minilibx-linux -c -ggdb -gdwarf-3

SRC_PATH = sources/
OBJ_PATH = objet/

SRC		= \
			so_long.c parsing.c \

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
HEAD	= -I ./header/

LIBFT_DIR = ./sources/ultimate_libft
LIBFT_INCLUDE = -I$(LIBFT_DIR)/includes
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD) $(LIBFT_INCLUDE)
	@echo "$(CYAN)🔧 Compilation de $(notdir $<)$(RESET)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@echo "$(YELLOW)📁 Dossier $(OBJ_PATH) créé$(RESET)"

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "$(GREEN)✅ libft_ultimate compilée avec succès !$(RESET)"

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(GREEN)✅ MiniLibX compilée avec succès !$(RESET)"

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	@$(CC) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -lX11 -lXext -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) créé avec succès !$(RESET)"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(YELLOW)🧹 Suppression des objets$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(MAKE) clean -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(RED)🗑️  Suppression complète$(RESET)"

re: fclean all

.PHONY: all clean fclean re
