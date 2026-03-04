NAME		= minishell

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
INCLUDES	= -I headers -I libft

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

LDFLAGS		= -L$(LIBFT_DIR) -lft -lreadline 

# ──────────────────────────── Sources ──────────────────────────── #

SRCS		= srcs/main.c \
				srcs/utils.c \
				srcs/parsing/parsing.c \
				srcs/parsing/command.c \
				srcs/parsing/operator.c \
				srcs/parsing/operator_p_two.c \
				srcs/parsing/operator_p_three.c \
				srcs/parsing/operator_p_four.c \
				srcs/parsing/rd.c \
				srcs/parsing/initialising.c \
				srcs/parsing/utils.c \
				srcs/parsing/handle_args.c \
				srcs/parsing/free_all.c \
				srcs/parsing/tokens/tokenizer.c \
				srcs/parsing/tokens/tokenizer_lsts.c \
				srcs/parsing/tokens/tokenizer_utils.c \
				srcs/parsing/tokens/tokenizer_utils2.c \
				srcs/exec/exec.c \
				srcs/exec/utils.c \
				srcs/exec/built_out/built_out.c \
				srcs/exec/built_out/child.c \
				srcs/exec/built_out/cmd.c \
				srcs/exec/built_out/utils.c \
				srcs/exec/builtin/builtin_cd.c \
				srcs/exec/builtin/builtin_echo.c \
				srcs/exec/builtin/builtin_env.c \
				srcs/exec/builtin/builtin_exit.c \
				srcs/exec/builtin/builtin_export.c \
				srcs/exec/builtin/builtin_pwd.c \
				srcs/exec/builtin/builtin_unset.c \
				srcs/exec/builtin/help_export_utils.c \
				srcs/exec/builtin/utils.c \
				srcs/exec/builtin/other_utils.c \
				srcs/exec/heredoc/heredoc.c \
				srcs/exec/heredoc/help.c \
				srcs/exec/heredoc/utils.c \
				srcs/expand/check_quotes.c \
				srcs/expand/expand.c \
				srcs/expand/fill_env_struct.c \
				srcs/expand/expand_utils.c \
				srcs/expand/expand_utils2.c \
				srcs/expand/expand_utils3.c \
				srcs/expand/expand_heredoc.c \
				srcs/signals.c

OBJS_DIR	= objs
OBJS		= $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

# ──────────────────────────── Rules ────────────────────────────── #

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
