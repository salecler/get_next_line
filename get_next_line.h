#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    char            *content;
    struct s_list   *next;
}   t_list;

int found_nl(t_list *stash);
t_list  *ft_lst_get_last(t_list *stash);
void    generate_line(size_t *stash, char **line);


#endif