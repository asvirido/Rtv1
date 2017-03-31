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

FLAGS = -Wall -Wextra -Werror -c -O3

MLX = -lmlx -framework OpenGL -framework AppKit

HEADER = head.h

MLX_SRC =	./SRC/mlx_src/create_img.c\
				./SRC/mlx_src/object_mlx.c\
				./SRC/mlx_src/create_xpm.c\
				./SRC/mlx_src/put_img.c\
				 

VECTOR =	./SRC/Vector/addition_vector.c\
			./SRC/Vector/cos_angle_between_vector.c\
			./SRC/Vector/module_vector.c\
			./SRC/Vector/multiplication_vector.c\
			./SRC/Vector/product_vectors.c\
			./SRC/Vector/scalar_vector.c\
			./SRC/Vector/subtraction_vector.c\
			./SRC/Vector/create_vector.c\

CREATE_RT =	./SRC/create_rt/create_ray.c\
				./SRC/create_rt/create_rt.c\
				./SRC/create_rt/create_sphere.c\

RT =	./SRC/ray_tracing/ray_tracing.c\
		./SRC/ray_tracing/intersect_ray_sphere.c\

SRC =	./SRC/main.c\
		$(VECTOR)\
		$(CREATE_RT)\
		$(MLX_SRC)\
		$(RT)\

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	@ gcc -o $(NAME) $(BINS) $(MLX)
	make clean

%.o: %.c $(HEADER)
	@ gcc $(FLAGS) -o  $@ $<

clean:
	@ /bin/rm -f $(BINS)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all
