# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjang <student.42seoul.kr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 03:49:53 by pjang             #+#    #+#              #
#    Updated: 2022/09/30 08:55:53 by pjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

LIBC	=	-L ./libft/ -lft
LFT		=	libft/libft.a
SRCS	= 	./srcs/check.c \
			./srcs/ft_atol.c \
			./srcs/get_index.c \
			./srcs/init.c \
			./srcs/is_integer.c \
			./srcs/lst_new.c \
			./srcs/parsing.c \
			./srcs/push_swap.c \
			./srcs/main.c \
			./srcs/push.c \
			./srcs/rotate.c \
			./srcs/rrotate.c \
			./srcs/put_error.c \
			./srcs/small_size_utils.c \
			./srcs/small_size.c \
			./srcs/swap.c \
			./srcs/print_re.c \
			./srcs/put_result.c 

OBJS	= $(SRCS:.c=.o)
RM		= rm -f

all : $(LFT) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBC)

$(LFT) :
	@make -s bonus -C libft
	@echo "Libft Success."

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -s $@ -C libft
	$(RM) $(OBJS)
	@echo "Object files removed."

fclean : clean
	@make -s $@ -C libft
	$(RM) $(NAME)
	@echo "Executable file removed."

re : fclean all

.PHONY : all clean fclean re