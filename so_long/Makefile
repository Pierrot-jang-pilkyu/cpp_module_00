# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjang <student.42seoul.kr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 03:49:53 by pjang             #+#    #+#              #
#    Updated: 2022/09/23 06:10:25 by pjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

LIBC	=	-L ./libft/ -lft -L ./mlx/ -lmlx -framework OpenGL -framework AppKit
MLX		=	mlx/libmlx.a
LFT		=	libft/libft.a
SRCS	= 	./src/ft_mlx_img.c \
			./src/game_clear.c \
			./src/game_close.c \
			./src/get_linelen.c \
			./src/get_map.c \
			./src/get_player_position.c \
			./src/inits.c \
			./src/keypress.c \
			./src/main.c \
			./src/map_check.c \
			./src/map_regen.c \
			./src/move.c \
			./src/put_error.c

OBJS	= $(SRCS:.c=.o)
RM		= rm -f

all : $(MLX) $(LFT) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBC)

$(MLX) : 
	@make -s -C mlx
	@echo "MLX Success."

$(LFT) :
	@make -s bonus -C libft
	@echo "Libft Success."

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -s $@ -C mlx
	@make -s $@ -C libft
	$(RM) $(OBJS)
	@echo "Object files removed."

fclean : clean
	@make -s $@ -C libft
	@make -s $@ -C mlx
	$(RM) $(NAME)
	@echo "Executable file removed."

re : fclean all

.PHONY : all clean fclean re