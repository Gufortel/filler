# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gufortel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/30 17:14:20 by gufortel          #+#    #+#              #
#    Updated: 2018/06/01 23:19:48 by gufortel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gufortel.filler

SRC = check.c\
	  check_best.c\
	  main.c\
	  pose.c\
	  recup.c\
	  recupnext.c\
	  solver.c\
	  solver1.c\
	  start.c\
	  trait.c\
	  trend.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@gcc -o $(NAME) $(OBJ) ./libft/libft.a

$(OBJ): $(SRC)
	@gcc -Wall -Wextra -Werror -c $(SRC) 

clean:
	@make -C ./libft/ clean
	@rm -Rf $(OBJ)

fclean: clean
	@make -C ./libft/ fclean
	@rm -Rf $(NAME)

re:	fclean all
