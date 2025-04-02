MAKEFLAGS		= --no-print-directory

NAME			=	push_swap
NAME_BONUS		=	checker
CC				=	clang
RM 				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -Iincludes -g3 -fsanitize=address
LIBFT			= -L./libft -lft
OBJS_DIR		=	objs
SRCS_DIR		=	src
BONUS_DIR		=	src_bonus

SRCS			=	$(SRCS_DIR)/push_swap.c\
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

SRC_BONUS		=	$(BONUS_DIR)/push_swap_bonus.c\
				$(BONUS_DIR)/push_bonus.c\
				$(BONUS_DIR)/free_bonus.c\
				$(BONUS_DIR)/checks_bonus.c\
				$(BONUS_DIR)/rotate_bonus.c\
				$(BONUS_DIR)/reverse_bonus.c\
				$(BONUS_DIR)/swap_bonus.c\
				$(BONUS_DIR)/utils_bonus.c\
				$(BONUS_DIR)/array_bonus.c\
				$(BONUS_DIR)/main_bonus.c\

OBJS			=	$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
OBJS_BONUS		=	$(patsubst $(BONUS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRC_BONUS))

RESET			= \033[0m
BLUE			= \033[34m
YELLOW			= \033[38;2;255;239;0m
APPLE_GREEN		= \033[38;2;141;182;0m
PINK			= \033[38;2;255;105;180m
RED				= \033[31m
CYAN			= \033[38;2;0;255;255m
VIOLET			= \033[38;2;138;43;226m
GOLD			= \033[38;2;255;215;0m
MAGENTA			= \033[38;2;255;0;255m

all: build $(NAME)

bonus: build $(NAME_BONUS)

$(NAME): $(OBJS)
	@echo "${PINK}💻 Compiling Push_Swap...${RESET}"
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "${YELLOW}✨ Push_Swap Executable Created 🥑 ${RESET}"

$(NAME_BONUS): $(OBJS_BONUS)
	@echo "${VIOLET}💻 Compiling Checker...${RESET}"
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "${YELLOW}✨ Checker Executable Created 🥑 ${RESET}"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c Makefile
	@echo "${CYAN}🔨  Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: $(BONUS_DIR)/%.c Makefile
	@echo "${PINK}🔨  Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

build:
	@mkdir -p $(OBJS_DIR)

clean:
	@echo "${RED}🧹 Removing Object Files...${RESET}"
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	@$(RM) $(OBJS_DIR)

fclean: clean
	@echo "${RED}🔥 Removing Executable Files...${RESET}"
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@echo "${GOLD}✨ All Executables Removed! Everything is Clean! ✅ ${RESET}"

re: fclean all

test:
	@echo "${MAGENTA}💥 Test Mode: Displaying Bonus Sources 📂...${RESET}"
	@echo "${TURQUOISE}${SRC_BONUS}${RESET}"

.PHONY: all clean build fclean re test bonus
