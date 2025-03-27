NAME = libftprintf.a

SRCS = ft_printf.c ft_print_hex.c ft_print_usd.c ft_print_ptr.c ft_putnbr.c ft_putchar.c ft_putstr.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = rc 

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) 
	ar $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
