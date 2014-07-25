#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/14 16:07:26 by rnicolas          #+#    #+#              #
#    Updated: 2014/06/26 17:01:24 by nsaintot         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 42sh

CC = llvm-gcc

LIBDIR = libft

LIB = libft.a

CFLAGS = -Wall -Wextra -Werror -I includes/ -I $(LIBDIR)/ -g

SRCDIR = ./srcs/

OBJDIR = ./objs/

SRC =	main.c      \
		parser3.c   \
		parser2.c   \
		parser.c    \
		lexer2.c    \
		lexer.c     \
		signal.c    \
		libaux.c    \
		env.c       \
		env2.c      \
		env3.c      \
		built_in.c  \
		prompt_1.c  \
		prompt_2.c  \
		alias1.c    \
		alias2.c    \
		unalias.c   \
		history.c   \
		history2.c  \
		env_var.c   \
		echo.c      \
		check_lex.c \
		trmcps.c    \
		prompt_3.c  \
		cursor.c    \
		arrow.c     \
		prompt_edit.c

LDFLAGS = -I includes -I $(LIBDIR) -L /usr/lib -ltermcap -L $(LIBDIR) -lft -g

OBJ = $(SRC:%.c=%.o)

OBJ_LIST = $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(LIB):
	@echo "Compile $(NAME)..\t\t\\033[0;33m\033[4m25%\033[0m"
	@$(MAKE) -C $(LIBDIR)

$(NAME): $(LIB) $(OBJ_LIST)
	@echo "\033[0;mBuild src..\t\t\033[0;33m\033[4m50%\033[24m\033[0;m"
	@$(CC) $(OBJ_LIST) -o $(NAME) $(LDFLAGS)
	@printf "\e[0mCompiled srcs:     \e[1;34m";ls $(OBJ_LIST) \
	| wc -l | cut -d' ' -f-8
	@echo "\033[0mBuild $(NAME) Completed.. \t\033[0;32m\033[4m100%\033[24m"
	@echo "\033[0;32mInstall .42shrc - Done ($(NAME))\033[0m"
	@ls $(HOME)/.42shrc >/dev/null 2>&1 || cp 42shrc $(HOME)/.42shrc >/dev/null

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@$(MAKE) -C $(LIBDIR) clean
	@echo "\033[1;31mRemove compiled srcs $(NAME)..\033[0;m"
	@/bin/rm -fr $(OBJ_LIST)

fclean: clean
	@/bin/rm -f $(LIBDIR)/$(LIB)
	@echo "\033[1;31mRemove $(NAME)..\033[0;m"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
