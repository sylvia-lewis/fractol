# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/16 16:24:25 by sylewis           #+#    #+#              #
#    Updated: 2019/11/13 11:49:30 by sylewis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

SOURCES		=	./srcs/main.c \
				./srcs/action.c \
				./srcs/fractals.c \
				./srcs/tools.c
				#./srcs/colour.c \
				
				
OBJ			=	$(SOURCES:.c=.o)

FLAGS		=	-Wall -Wextra -Werror -g
INCLUDES	=	-I ./includes -I ./libft/includes
LIB			=	-L /usr/local/lib/
FRAMEWORK	=	-framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): remake $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) -lmlx $(FRAMEWORK) -L libft -lft
 
remake :
	make -C libft/

%.o: %.c
	gcc $(FLAGS) -o $@ -c $< $(INCLUDES)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
