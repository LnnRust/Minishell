NAME = minishell
CC = clang
CFLAGS = -Wall -Wextra -Werror -g3 -O0
LDFLAGS = -lreadline
CPPFLAGS = -Iincludes
RM = rm -f

# Sanitizers should ONLY be used with clang. Some flags will NOT compile with gcc.
# Some flags are probably useless or redundant.
ASan			= 	-fsanitize-recover=address -fsanitize=address -fsanitize-address-use-after-return=always -fsanitize-address-use-after-scope -fno-optimize-sibling-calls -fno-omit-frame-pointer -fno-common
MSan			=	-fsanitize=memory -fsanitize-memory-track-origins -fno-omit-frame-pointer
TSan			=	-fsanitize=thread
UBSan			=	-fsanitize=undefined -fsanitize=float-divide-by-zero -fsanitize=integer -fsanitize=bounds \
					-fsanitize=implicit-integer-truncation -fsanitize=implicit-integer-arithmetic-value-change \
					-fsanitize=implicit-conversion -fsanitize=integer -fsanitize=nullability -fsanitize=vptr \
					-fno-sanitize-merge -fno-omit-frame-pointer

# SANITIZE		= $(ASan) $(UBSan)

SRCS = \
	srcs/minishell.c \
	srcs/signal_handler.c \
	srcs/environment.c \
	#srcs/tokenizer.c \
	#srcs/tokenizer_lsts.c \
	#srcs/tokenizer_utils.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean remakefile format

all: $(NAME)

$(NAME): $(OBJS)
#	-norminette
	make -j$(nproc) -C includes/ft_printf
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SANITIZE) -o $@ $^ includes/ft_printf/libftprintf.a $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SANITIZE) -c $< -o $@

clean:
	make clean -C includes/ft_printf
	$(RM) $(OBJS) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all
