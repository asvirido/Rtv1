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

SRC = ./SRC/main.c

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	make -C libft/
	gcc -o $(NAME) $(BINS) $(MLX)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -o  $@ $<

clean:
	 /bin/rm -f $(BINS)
	 make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

all_clean: all clean
