NAME = push_swap
SRCS = push_swap.c rules1.c rules2.c rules3.c utils1.c utils2.c utils3.c utils4.c utils5.c utils6.c utils7.c ft_split.c utils8.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re