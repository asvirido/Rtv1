# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makafile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asvirido <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 14:27:54 by asvirido          #+#    #+#              #
#    Updated: 2017/02/17 12:00:54 by asvirido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

FLAGS = -c -O2

MLX = -lmlx -framework OpenGL -framework AppKit

HEADER = head.h

VECTOR =./SRC/Vector/addition_vector.c\
		./SRC/Vector/cos_angle_between_vector.c\
		./SRC/Vector/module_vector.c\
		./SRC/Vector/multiplication_vector.c\
		./SRC/Vector/product_vectors.c\
		./SRC/Vector/scalar_vector.c\
		./SRC/Vector/subtraction_vector.c\

SRC =	./SRC/main.c\
		$(VECTOR)\

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	@ gcc -o $(NAME) $(BINS) $(MLX)

%.o: %.c $(HEADER)
	@ gcc $(FLAGS) -o  $@ $<

clean:
	@ /bin/rm -f $(BINS)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all
