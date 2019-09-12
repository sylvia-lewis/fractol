# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 14:55:39 by sylewis           #+#    #+#              #
#    Updated: 2019/05/06 19:10:38 by sylewis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./ft_atoi.c\
	   ./ft_bzero.c\
	   ./ft_isalnum.c\
	   ./ft_isalpha.c\
	   ./ft_isascii.c\
	   ./ft_isdigit.c\
	   ./ft_isprint.c\
	   ./ft_itoa.c\
	   ./ft_lstadd.c\
	   ./ft_lstdel.c\
	   ./ft_lstdelone.c\
	   ./ft_lstiter.c\
	   ./ft_lstmap.c\
	   ./ft_lstnew.c\
	   ./ft_memalloc.c\
	   ./ft_memccpy.c\
	   ./ft_memchr.c\
	   ./ft_memcmp.c\
	   ./ft_memcpy.c\
	   ./ft_memdel.c\
	   ./ft_memmove.c\
	   ./ft_memset.c\
	   ./ft_putchar.c\
	   ./ft_putchar_fd.c\
	   ./ft_putendl.c\
	   ./ft_putendl_fd.c\
	   ./ft_putnbr.c\
	   ./ft_putnbr_fd.c\
	   ./ft_putstr.c\
	   ./ft_putstr_fd.c\
	   ./ft_strcat.c\
	   ./ft_strchr.c\
	   ./ft_strclr.c\
	   ./ft_strcmp.c\
	   ./ft_strcpy.c\
	   ./ft_strdel.c\
	   ./ft_strdup.c\
	   ./ft_strequ.c\
	   ./ft_striter.c\
	   ./ft_striteri.c\
	   ./ft_strjoin.c\
	   ./ft_strlcat.c\
	   ./ft_strlen.c\
	   ./ft_strmap.c\
	   ./ft_strmapi.c\
	   ./ft_strncat.c\
	   ./ft_strncmp.c\
	   ./ft_strncpy.c\
	   ./ft_strnequ.c\
	   ./ft_strnew.c\
	   ./ft_strnstr.c\
	   ./ft_strrchr.c\
	   ./ft_strsplit.c\
	   ./ft_strstr.c\
	   ./ft_strsub.c\
	   ./ft_strtrim.c\
	   ./ft_tolower.c\
	   ./ft_toupper.c\
	   ./ft_swap.c\
	   ./ft_div_mod.c\
	   ./ft_strrev.c\
	   ./ft_sort_integer_table.c\
	   ./ft_sqrt.c\
	   ./ft_factorial.c\
	   ./ft_is_prime.c\
	   ./ft_find_next_prime.c\
	   ./ft_power.c\
	   ./get_next_line.c\

OBJECTS = $(SRCS:.c=.o) 

INCL = ./includes/

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS): $(SRCS)
	gcc -c -Wall -Wextra -Werror $(SRCS) -I$(INCL)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
