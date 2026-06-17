NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar
ARFLAGS = rcs
SRCS = $(addsuffix .c, $(addprefix utils/, \
        ft_strncmp ft_strlen ft_strlcpy ft_strlcat \
        ft_striteri ft_substr ft_split ft_strchr ft_strdup \
        ft_strjoin ft_strmapi ft_strnstr ft_strrchr ft_strtrim \
        ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower \
        ft_memcmp ft_calloc ft_memset ft_memchr ft_bzero ft_memcpy ft_memmove \
        ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd \
        ft_atoi ft_itoa \
        ft_lstsize ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
        ft_lstiter ft_lstlast ft_lstmap ft_lstnew)) \
       $(addsuffix .c, $(addprefix printf/, \
        ft_print_chars ft_print_hex ft_print_nums ft_printf))
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re