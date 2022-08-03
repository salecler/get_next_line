CC = gcc
CFLAGS = -Wall -Wextra -Werror

make: gcc -Wall -Wextra -Werror get_next_line.c get_next_line.h get_next_line_utils.c -o gnl && ./gnl
