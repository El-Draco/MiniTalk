# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 19:37:03 by rriyas            #+#    #+#              #
#    Updated: 2021/12/29 12:22:51 by rriyas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk
CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME):
		${CC} ${CFLAGS} mini_utils.c server.c -o server
		${CC} ${CFLAGS} mini_utils.c client.c -o client

bonus:	client server
		${CC} ${CFLAGS} mini_utils.c client_bonus.c -o client
		${CC} ${CFLAGS} mini_utils.c server_bonus.c -o server

all:	$(NAME)

clean:
		${RM} client server

fclean:	clean

re:		fclean all

.PHONY: minitalk bonus all clean fclean re
