NAME_C = client
NAME = server
SOURCES_C = client.c utils.c
SOURCES_S = server.c
OBJ_C = $(SOURCES_C:.c=.o)
OBJ_S = $(SOURCES_S:.c=.o)

%.o:%.c header.h
	cc -Wall -Wextra -Werror -c $< -o $@

$(NAME_C) : $(OBJ_C)
	cc -Wall -Wextra -Werror client.c utils.c -o client

$(NAME_S) : $(OBJ_S)
	cc -Wall -Wextra -Werror server.c -o server

all : $(NAME_S NAME_C)

clean:
	rm -f $(OBJ_C) $(OBJ_S)

fclean: clean
	rm -f $(NAME_S) (NAME_C)

re: fclean all

.PHONY: clean