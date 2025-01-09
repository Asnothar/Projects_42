# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 11:47:43 by abeaufil          #+#    #+#              #
#    Updated: 2025/01/06 13:45:34 by abeaufil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRC_PATH = source/
OBJ_PATH = objet/

SRC		= main.c \
		swap.c push.c rotate.c reverse_rotate.c \
		utils.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
HEAD	= -I ./header/ -I ../../Cercle_1/libft/include


all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	@${MAKE} -C ../../Cercle_1/libft
	$(CC) $(CFLAGS) $(OBJS) ../../Cercle_1/libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)
	@${MAKE} -C ../../Cercle_1/libft clean

fclean: clean
	rm -f $(NAME)
	@${MAKE} -C ../../Cercle_1/libft fclean

re: fclean all

.PHONY: all clean fclean re