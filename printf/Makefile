# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/01 11:18:24 by fbachman          #+#    #+#              #
#    Updated: 2026/06/03 11:20:58 by fbachman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar
ARFLAGS = rcs
SRCS = $(addsuffix .c, \
		ft_printf \
		ft_print_chars \
		ft_print_nums \
		ft_print_hex)
OBJS = $(SRCS:.c=.o)
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "Compiled successfully! 🚀"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
	@echo "Object files cleaned."

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	@echo "All clear! 🧹"

re: fclean all

.PHONY: all clean fclean re