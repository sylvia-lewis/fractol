# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/16 16:24:25 by sylewis           #+#    #+#              #
#    Updated: 2019/11/11 17:45:42 by sylewis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

SOURCES		=	./srcs/main.c \
				./srcs/action.c \
				./srcs/fractals.c \
				#./srcs/tools.c
				#./srcs/colour.c \
				#./srcs/display.c \
				
				#./srcs/hud.c \
				
				
OBJ			=	$(SOURCES:.c=.o)

FLAGS		=	-Wall -Wextra -Werror -g
INCLUDES	=	-I ./includes -I ./libft/includes
LIB			=	-L /usr/local/lib/
FRAMEWORK	=	-framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): remake $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) -lmlx $(FRAMEWORK) -L libft/ -lft
 
remake :
	make -C libft/

%.o: %.c
	gcc $(FLAGS) -o $@ -c $< $(INCLUDES)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:
	fclean all
