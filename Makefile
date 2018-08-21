# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cletinic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/24 11:04:12 by cletinic          #+#    #+#              #
#    Updated: 2018/08/15 16:35:19 by cletinic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DISCLAIMER:
# MinilibX is licensed under the BSD license: Copyright Olivier Crouzet & Charlie Root
# The mlx in this folder is a mirror of mlx created by Pierre Bondoerffer (pbondoer) https://github.com/pbondoer/MinilibX
# (with slight modifications to compile wolf3d)
# curl -O https://github.com/pbondoer/MinilibX/archive/master.zip
# mv master.zip minilibx.zip

NAME = wolf3d
FLAG = -Wall -Wextra -Werror -Wuninitialized
SRC = main.c reader.c errors.c raycaster.c movement.c drawer.c surroundings.c input.c
OBJ = $(SRC:.c=.o)
GIT = "./min"

$(NAME):
	
	#curl -O https://github.com/pbondoer/MinilibX/archive/master.zip
	#mv master.zip
	#unzip master.zip
	make re -C minilibx/ && make clean minilibx/
	make re -C libft/ && make clean -C libft/
	gcc -Wall -Wextra -Werror -I minilibx/ -L minilibx/ -lmlx -framework OpenGL -framework AppKit $(SRC) -L libft/ -lft -o $(NAME)

#$(GIT):
#	if [ ! -d $(GIT) ]; then git clone https://github.com/pbondoer/MinilibX.git min; fi
#	rm -rf ./min/.git

#all: $(GIT) $(NAME)
all: $(NAME)

clean: drawer.c
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
