# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 17:33:23 by marcnava          #+#    #+#              #
#    Updated: 2024/10/14 19:14:14 by marcnava         ###   ########.fr        #
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
				ft_printf.c \
				ft_printf_utils.c \
				ft_conversion_utils.c \
				ft_mod_printf.c

SRCS_B		=	\
				_bonus/ft_printf_bonus.c

OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

# *************************************************************************** #
#		RULES		#

all: 			$(NAME)

$(NAME):		$(OBJS)
				cd libft && make && make bonus
				mv libft/libft.a $(NAME) && cd ..
				$(LIB) $(NAME) $(OBJS)

.o:				.c $(HEADER)
				$(COMPILER) -c $< -o $@

clean:
				$(RM) $(OBJS) $(OBJS_B)
				cd libft && make fclean
				cd ..

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:			$(NAME) $(OBJS_B)
				$(LIB) $(NAME) $(OBJS_B)

.PHONY:			all clean fclean re bonus