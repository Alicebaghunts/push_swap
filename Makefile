NAME = push_swap

CHECK = checker

SRCS =  $(wildcard src/*.c utils/*.c)

OBJS_DIR = obj

SRC_DIR = src

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes #-g3 -fsanitize=address

RM = rm -rf

all: build ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

${CHECK}: ${CHECK_OBJS} 
	@${CC} ${CFLAGS} ${CHECK_OBJS} ./libft/libft.a -o ${CHECK}

build:
	mkdir -p $(OBJS_DIR)

echo:
	@echo ${SRCS}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}
	@${RM} ${OBJS_DIR}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}


re: fclean all

.PHONY: all clean fclean re