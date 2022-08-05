CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=42

NAME = gnl

SOURCE =	src/get_next_line.c	\
			src/get_next_line_utils.c

INCLUDE = -I ./include

OBJECTS = $(SOURCE:%c=%o) #$(patsubst %.c,%.o,$(SOURCE))

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

$(NAME): $(OBJECTS) include/get_next_line.h
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJECTS) -o $(NAME)


clean:
	@rm -rf $(OBJECTS)

fclean:	clean
	@rm -fr $(NAME)

re: fclean all
