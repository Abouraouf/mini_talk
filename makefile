NAME_C = client
NAME_S = server
SOURCES_C = client.c utils.c
SOURCES_S = server.c utils.c
OBJ_C = $(SOURCES_C:.c=.o)
OBJ_S = $(SOURCES_S:.c=.o)

%.o: %.c header.h
	cc -c $< -o $@

$(NAME_C): $(OBJ_C)
	cc $(OBJ_C) -o $(NAME_C)

$(NAME_S): $(OBJ_S)
	cc $(OBJ_S) -o $(NAME_S)

all: $(NAME_S) $(NAME_C)

clean:
	rm -f $(OBJ_C) $(OBJ_S)

fclean: clean
	rm -f $(NAME_S) $(NAME_C)

re: fclean all

.PHONY: clean
