# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 05:43:30 by ancourti          #+#    #+#              #
#    Updated: 2026/01/25 10:43:45 by ancourti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_printf.c ft_printf_utils.c
OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g3 -O0

NAME			= libftprintf.a

all:		$(NAME)

libft.a:
		make -j$(nproc) -C ../libft/
		cp ../libft/libft.a libftprintf.a

$(NAME):	libft.a $(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
				make clean -C ../libft/
				$(RM) $(OBJS) $(BONUS_OBJS) $(NAME)

fclean:			clean
				$(RM) $(NAME)
				$(RM) ../libft/libft.a

re:				fclean $(NAME)

# bonus:			$(OBJS) $(BONUS_OBJS)
# 				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
