# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisner <aisner@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 04:09:09 by aisner            #+#    #+#              #
#    Updated: 2022/01/23 15:04:17 by aisner           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Boomerang

INCL = ./

VPATH =		libft \
				files

HEADERS	 =		minitalk.h \
				libft/libft.h

MYLIB	=	libft/libft.a

##   CLIENT_FILES AND SERVER without bonus part      ########################################

CLIENT_FILES =		client.c \
					utilits.c

O_CLIENT_FILES = 	$(addprefix objects/, $(CLIENT_FILES:.c=.o))

SERVER_FILES =		server.c \
					utilits.c

O_SERVER_FILES =	$(addprefix objects/, $(SERVER_FILES:.c=.o))

##   SERVER_FILES AND CLIENT witn bonus part         ########################################

CLIENT_FILES_B =	client_bonus.c utilits.c

O_CLIENT_FILES_B = 	$(addprefix objects/, $(CLIENT_FILES_B:.c=.o))

SERVER_FILES_B =	server_bonus.c utilits.c

O_SERVER_FILES_B =	$(addprefix objects/, $(SERVER_FILES_B:.c=.o))

##   RULES                                           ########################################

CFLAGS =	-Wall -Wextra -Werror -O3
BL =		\033[1m\033[32m
W =			\033[38;2;255;255;255

all		:	objects $(O_SERVER_FILES) $(O_CLIENT_FILES) server client

client	:	$(O_CLIENT_FILES) $(MYLIB)
			@$(CC) $(CFLAGS) $(O_CLIENT_FILES) $(MYLIB) -o client
			@sleep 0.2
			@echo ">>>$(BL) client$(W);0m is ready for data exchange"
			@sleep 0.2
			@echo "$(W);m           run \033[;1m./client$(W);m [PID] [MESSAGE] >>>\n"

server	:	$(O_SERVER_FILES) $(MYLIB)
			@$(CC) $(CFLAGS) $(O_SERVER_FILES) $(MYLIB) -o server
			@sleep 0.7
			@clear ; echo ""; echo ">>>$(BL) server$(W);0m is ready for data exchange"
			@sleep 0.2
			@echo "$(W);m           run \033[;1m./server$(W);m to generate PID >>>\n"

bonus	:			objects $(O_SERVER_FILES_B) $(O_CLIENT_FILES_B) server_bonus client_bonus
client_bonus	:	$(O_CLIENT_FILES_B) $(MYLIB)
					@$(CC) $(CFLAGS) $(O_CLIENT_FILES_B) $(MYLIB) -o client_bonus
					@sleep 0.2
					@echo ">>>$(BL) client_bonus$(W);0m is ready for data exchange"
					@sleep 0.2
					@echo "$(W);m                 run \033[;1m./client_bonus$(W);m [PID] [MESSAGE] >>>\n"

server_bonus	:	$(O_SERVER_FILES_B) $(MYLIB)
					@$(CC) $(CFLAGS) $(O_SERVER_FILES_B) $(MYLIB) -o server_bonus
					@sleep 0.7
					@clear ; echo ""
					@clear ; echo ""; echo ">>>$(BL) server_bonus$(W);0m is ready for data exchange"
					@sleep 0.2
					@echo "$(W);m                 run \033[;1m./server_bonus$(W);m to generate PID >>>\n"

objects :
					@mkdir $@

$(MYLIB):
					make -C libft/

objects/%.o :		%.c $(HEADERS)
					gcc $(CFLAGS) -I $(INCL) -c $< -o $@

##    CLEAN                                           ########################################

clean :
			@rm -rf objects/
			@make clean -C libft/
			@echo "removing [objects] [libft/objects]"

fclean :	clean
			@rm -f server client
			@rm -f server_bonus client_bonus
			@make fclean -C libft/
			@echo "removing [server] [client] [server_bonus] [client_bonus] [libft]"
re :		fclean all

.PHONY =	all	clean fclean re