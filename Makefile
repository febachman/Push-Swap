NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar
ARFLAGS = rcs
SRCS = PREENCHER!!!!!!!!
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
	@echo "Object files cleaned! 📦"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	@echo "All clear! 🧹"

re: fclean all

.PHONY: all clean fclean re