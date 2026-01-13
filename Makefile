NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline
CPPFLAGS = -Iincludes
RM = rm -f

SRCS = \
	srcs/minishell.c \
	srcs/tokenizer.c \
	srcs/tokenizer_lsts.c \
	srcs/tokenizer_utils.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean remakefile format

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
