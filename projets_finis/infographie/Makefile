#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/25 17:22:42 by rnicolas          #+#    #+#              #
#    Updated: 2014/03/03 16:53:36 by hmichals         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = raytracer

CC = llvm-gcc

LIB = libft.a

LIBDIR = libft

CFLAGS = -Wall -Wextra -Werror -O3 -I includes/ -I $(LIBDIR) -g

SRCDIR = ./srcs/

OBJDIR = ./objs/

SRC =	main.c \
		tab_func.c \
		info.c \
		res_equ_thrd.c \
		quad.c \
		parse_scene.c \
		error.c \
		create_list2.c \
		create_list.c \
		cone.c \
		intersection.c \
		cylinder.c \
		plane.c \
		sphere.c \
		list_object.c \
		maths_obj.c \
		maths_unit.c \
		camera.c \
		mlx.c \
		maths_vec.c \
		maths_rot.c \
		display.c \
		color.c \

LDFLAGS = -I includes -I $(LIBDIR) -g -L $(LIBDIR) -lft -L /usr/X11/lib -lmlx -lX11 \
-lXext

OBJ = $(SRC:%.c=%.o)

OBJ_LIST = $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_LIST)
	$(MAKE) -C $(LIBDIR)
	$(CC) $(OBJ_LIST) -o $(NAME) $(LDFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(MAKE) -C $(LIBDIR) clean
	/bin/rm -fr $(OBJ_LIST)

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all

$(LIB):
	$(MAKE) -C $(LIBDIR)

.PHONY: all clean fclean re $(LIB)
