NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR)
AR = ar
ARFLAGS = rcs
SRCS = $(addsuffix .c, \
        op_pop_node op_populate_stack op_push_back op_push_front \
		op_push op_rotate op_rrotate op_swap \
		parse_args parse_bench parse_flags parse_nbr main\
		sort_disorder_metric sort_small sort_simple sort_medium)
OBJS = $(SRCS:.c=.o)
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
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