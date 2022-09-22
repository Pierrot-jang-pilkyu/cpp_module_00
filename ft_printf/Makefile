# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjang <student.42seoul.kr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 00:19:43 by pjang             #+#    #+#              #
#    Updated: 2022/05/31 03:54:14 by pjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCS	= include/

LSRCS	=	libft/ft_atoi.c \
			libft/ft_bzero.c \
			libft/ft_calloc.c \
			libft/ft_isalnum.c \
			libft/ft_isalpha.c \
			libft/ft_isascii.c \
			libft/ft_isdigit.c \
			libft/ft_isprint.c \
			libft/ft_itoa.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_memcpy.c \
			libft/ft_memmove.c \
			libft/ft_memset.c \
			libft/ft_putchar_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_split.c \
			libft/ft_strchr.c \
			libft/ft_strdup.c \
			libft/ft_striteri.c \
			libft/ft_strjoin.c \
			libft/ft_strlcat.c \
			libft/ft_strlcpy.c \
			libft/ft_strlen.c \
			libft/ft_strmapi.c \
			libft/ft_strncmp.c \
			libft/ft_strnstr.c \
			libft/ft_strrchr.c \
			libft/ft_strtrim.c \
			libft/ft_substr.c \
			libft/ft_tolower.c \
			libft/ft_toupper.c

SRCS	= 	ft_printf.c \
			srcs/get_conversion_index.c \
			srcs/is_conversion.c \
			srcs/print_char.c \
			srcs/print_nbr_base.c \
			srcs/print_ptr.c \
			srcs/print_str.c \
			srcs/put_format.c \
			srcs/put_nonflag.c

LOBJS	= $(LSRCS:.c=.o)

OBJS	= $(SRCS:.c=.o)
NAME	= libftprintf.a
LIBFT	= libft
LIBFT_LIB		= libft.a
LIBC	= ar -rcs
RM		= rm -f
CP		= cp

all : $(NAME)

$(NAME) : $(LIBFT)/$(LIBFT_LIB) $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

$(LIBFT)/$(LIBFT_LIB) : $(LOBJS)
	$(LIBC) $(LIBFT)/$(LIBFT_LIB) $(LOBJS)
	$(CP) $(LIBFT)/$(LIBFT_LIB) $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

clean :
	$(RM) $(LOBJS)
	$(RM) $(OBJS)
	$(RM) $(LIBFT)/$(LIBFT_LIB)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
