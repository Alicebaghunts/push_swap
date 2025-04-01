NAME = push_swap

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -Iincludes -g3 -fsanitize=address

SRCS_DIR = src

SRCS = $(wildcard $(SRCS_DIR)/*.c $(SRCS_BONUS_DIR)/*.c)

OBJS_DIR = obj

OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all: build $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p $(OBJS_DIR)

clean: 
	$(MAKE) -C ./libft fclean
	$(RM) $(OBJS)
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean build fclean re
