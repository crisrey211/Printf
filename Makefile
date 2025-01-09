# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: creynalt <creynalt@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 17:04:07 by creynalt          #+#    #+#              #
#    Updated: 2025/01/09 12:57:35 by creynalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = cc
CCFLAGS = -Wall -Wextra -Werror

NAME = ft_printf.a
SRC = ft_printf.c ft_utils.c ft_libft.c
OBJ = $(SRC:.c=.o)
INCLUDE = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

%.o: %.cd
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re