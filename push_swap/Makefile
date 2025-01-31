# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 11:47:43 by abeaufil          #+#    #+#              #
#    Updated: 2025/01/31 14:23:01 by abeaufil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRC_PATH = source/
OBJ_PATH = objet/

SRC		= main.c \
		swap.c push.c rotate.c reverse_rotate.c \
		parse.c \
		sort_small.c full_sort.c\
		full_cost.c full_move.c full_pos.c \
		utils.c  stack_utils.c  \
		

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
HEAD	= -I ./header/


all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re