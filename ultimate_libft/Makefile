# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:10:56 by abeaufil          #+#    #+#              #
#    Updated: 2025/02/20 11:01:45 by abeaufil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -ggdb -gdwarf-3
AR		= ar rcs
RM		= rm -f

LIBFT_PATH   = sources/sources_libft/
PRINTF_PATH  = sources/sources_printf/
OBJ_PATH     = objet/

LIBFT_SRC = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
	ft_putendl_fd.c ft_split.c ft_itoa.c

BONUS = \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c

PRINTF_SRC = \
	ft_printf.c \
	print_char.c print_hex.c print_pointer.c print_string.c \
	print_int.c print_unsigned.c

SRCS        = $(addprefix $(LIBFT_PATH), $(LIBFT_SRC))
BONUS_SRCS  = $(addprefix $(LIBFT_PATH), $(BONUS))
PRINTF_SRCS = $(addprefix $(PRINTF_PATH), $(PRINTF_SRC))

OBJS        = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
BONUS_OBJS  = $(addprefix $(OBJ_PATH), $(BONUS:.c=.o))
PRINTF_OBJS = $(addprefix $(OBJ_PATH), $(PRINTF_SRC:.c=.o))

HEAD = -I ./header/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(LIBFT_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(PRINTF_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(PRINTF_OBJS)
	$(AR) $(NAME) $(OBJS) $(PRINTF_OBJS)

bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS)

fclean: clean
	$(RM) $(NAME)
	rm -rf $(OBJ_PATH)

re: fclean all
