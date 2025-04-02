MAKEFLAGS = --no-print-directory

NAME		=	push_swap

NAME_BONUS	=	checker

CC			=	clang

RM = rm -rf

CFLAGS		=	-Wall -Wextra -Werror -Iincludes -g3 -fsanitize=address

SRCS_DIR = src

SRCS		=	$(SRCS_DIR)/push_swap.c\
				$(SRCS_DIR)/push.c\
				$(SRCS_DIR)/free.c\
				$(SRCS_DIR)/checks.c\
				$(SRCS_DIR)/sort.c\
				$(SRCS_DIR)/butterfly.c\
				$(SRCS_DIR)/rotate.c\
				$(SRCS_DIR)/reverse.c\
				$(SRCS_DIR)/swap.c\
				$(SRCS_DIR)/utils.c\
				$(SRCS_DIR)/array.c\
				$(SRCS_DIR)/print.c

BONUS_DIR = src_bonus

SRC_BONUS	=	$(BONUS_DIR)/push_swap_bonus.c\
				$(BONUS_DIR)/push_bonus.c\
				$(BONUS_DIR)/free_bonus.c\
				$(BONUS_DIR)/checks_bonus.c\
				$(BONUS_DIR)/rotate_bonus.c\
				$(BONUS_DIR)/reverse_bonus.c\
				$(BONUS_DIR)/swap_bonus.c\
				$(BONUS_DIR)/utils_bonus.c\
				$(BONUS_DIR)/array_bonus.c\
				$(BONUS_DIR)/main_bonus.c\

RESET			= \033[0m
BLUE			= \033[34m
YELLOW			= \033[38;2;255;239;0m
APPLE_GREEN		= \033[38;2;141;182;0m

OBJS		= 	$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

OBJS_BONUS	= 	$(patsubst $(BONUS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRC_BONUS))

OBJS_DIR = objs

LIBFT = -L./libft -lft

all: build $(NAME)

test:
	@echo $(SRC_BONUS)

$(NAME): $(OBJS)
	@echo "${APPLE_GREEN} Compiling $<${RESET}"
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "${YELLOW}Push_Swap created 🥑 ${RESET}"

bonus: build $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@echo "${APPLE_GREEN} Compiling $<${RESET}"
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "${YELLOW}Checker created 🥑 ${RESET}"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c Makefile
	@echo "${APPLE_GREEN} Compiling $<${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: $(BONUS_DIR)/%.c Makefile
	@echo "${APPLE_GREEN} Compiling $<${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

build:
	@mkdir -p $(OBJS_DIR)

clean:
	@echo "${BLUE} Removing libft object_files $(BUILD)${RESET}"
	@echo "${BLUE} Removing push_swap object_files $(BUILD)${RESET}"
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	@$(RM) $(OBJS_DIR)

fclean: clean
	@echo "${BLUE} Removing push_swap $(BUILD)${RESET}"
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@echo "${YELLOW} Everything is cleared ✅${RESET}"

re: fclean all

.PHONY: all clean build fclean re
