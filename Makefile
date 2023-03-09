# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 13:35:39 by aaghbal           #+#    #+#              #
#    Updated: 2023/02/10 13:35:49 by aaghbal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
CMLX = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
N_BONUS = so_long_bonus

UTILS = utils.c \
	pathvalid.c \
	pathvalid2.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_exten.c

SRC = $(UTILS) parsing.c move.c so_long.c 
BNS = $(UTILS) move_coin_bonus.c parsing_bonus.c move_enemy_bonus.c utils_bonus.c \
					move_bonus.c ft_itoa_bonus.c so_long_bonus.c

OB_SRC = $(SRC:.c=.o)
OB_BNS = $(BNS:.c=.o)
RM = rm -rf

all : $(NAME)

$(NAME) : $(OB_SRC) so_long.h
	$(CC) $(CMLX) $(OB_SRC) -o $(NAME)

bonus : $(OB_BNS) so_long_bonus.h
	$(CC) $(CMLX) $(OB_BNS) -o $(N_BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(OB_SRC)
	$(RM) $(OB_BNS)

fclean : clean
	$(RM) $(NAME) $(N_BONUS) 


re : fclean all

.PHONY: all clean re



