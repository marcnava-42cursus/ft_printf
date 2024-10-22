# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 17:33:23 by marcnava          #+#    #+#              #
#    Updated: 2024/10/22 21:48:40 by marcnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *************************************************************************** #
#		VARIABLES	#

NAME		=	libftprintf.a

CC			=	cc
RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

COMPILER	=	$(CC) $(CFLAGS)
LIB			=	ar rcs

HEADER		=	ft_printf.h

# *************************************************************************** #
#		FILES		#

SRCS 		=	\
				ft_printf_bonus.c \
				ft_flag_checker.c \
				ft_flag_parser.c \

OBJS		=	$(SRCS:.c=.o)

# *************************************************************************** #
#		RULES		#

all: 			$(NAME)

$(NAME):		$(OBJS)
				cd ../libft && make && make bonus
				mv ../libft/libft.a $(NAME) && cd ../_bonus
				$(LIB) $(NAME) $(OBJS)

.o:				.c $(HEADER)
				$(COMPILER) -c $< -o $@

clean:
				$(RM) $(OBJS) $(OBJS_B)
				cd ../libft && make fclean
				cd ../_bonus

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:			$(NAME) $(OBJS_B)
				$(LIB) $(NAME) $(OBJS_B)

.PHONY:			all clean fclean re bonus