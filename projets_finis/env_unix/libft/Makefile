#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/25 13:31:45 by rnicolas          #+#    #+#              #
#    Updated: 2014/06/25 18:09:09 by nsaintot         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIBC =	ft_memccpy.c \
		ft_putnbr.c \
		ft_strequ.c \
		ft_strncpy.c \
		ft_memchr.c \
		ft_putnbr_fd.c \
		ft_strnequ.c \
		ft_strsplit.c \
		ft_atoi.c \
		ft_memcmp.c \
		ft_putstr.c \
		ft_striter.c \
		ft_strnew.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_putstr_fd.c \
		ft_striteri.c \
		ft_strnstr.c \
		ft_isalnum.c \
		ft_memdel.c \
		ft_strcat.c \
		ft_strjoin.c \
		ft_strrchr.c \
		ft_isalpha.c \
		ft_memmove.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strstr.c \
		ft_isascii.c \
		ft_memset.c \
		ft_strclr.c \
		ft_strlen.c \
		ft_strsub.c \
		ft_isdigit.c \
		ft_putchar.c \
		ft_strcmp.c \
		ft_strmap.c \
		ft_strtrim.c \
		ft_isprint.c \
		ft_putchar_fd.c \
		ft_strcpy.c \
		ft_strmapi.c \
		ft_tolower.c \
		ft_itoa.c \
		ft_putendl.c \
		ft_strdel.c \
		ft_strncat.c \
		ft_toupper.c \
		ft_memalloc.c \
		ft_putendl_fd.c \
		ft_strdup.c \
		ft_strncmp.c \
		ft_itoa.c \
		get_next_line.c \
		free_table.c \
		table_len.c \
		ft_strisnum.c \
		ft_append.c \
		ft_strncpy.c

LIBO = $(LIBC:%.c=%.o)

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

$(NAME):	$(LIBO)
			@echo "Compile libft..\t\t\\033[0;33m\033[4m25%\033[0m"
			@ar rc $(NAME) $(LIBO)
			@printf "\e[0mCompiled srcs:     \e[1;34m";ls $(OBJ_LIST) \
	| wc -l | cut -d' ' -f-8
			@ranlib $(NAME)
			@echo "\033[0mBuild libft Completed.. \033[0;32m\033[4m100%\033[24m"

all:		$(NAME)

clean:
			@echo "\033[1;31mRemove compiled srcs libft..\033[0;m"
			@rm -f $(LIBO)

fclean:		clean
			@echo "\033[1;31mRemove libft..\033[0;m"
			@rm -f $(NAME)

re:			fclean all

%.o:		%.c
			@llvm-gcc -o $@ -c $< $(FLAGS) -g

.PHONY:		all clean re fclean
