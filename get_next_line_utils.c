#include "get_next_line.h"

int found_nl(t_list *stash)
{
    int     i;
    t_list *current;

    if (!stash)
        return (0);
    current = ft_lst_get_last(stash)
    i = 0;
    while (current->content)
    {
        if (current->content[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

t_list  *ft_lst_get_last(t_list *stash)
{
    t_list  *current;

    current = stash;
    while (current && current->next)
        current = current->next;
    return (current);
}

void    generate_line(size_t *stash, char **line)
{
    int i;
    int len;

    len = 0;
    while (stash)
    {
        i = 0;
        while (stash->content[i])
        {
            if (stash->content[i] == '\n')
            {
                len++;
                break;
            }
            len++;
            i++;
        }
        stash = stash->next;
    }
    *line = malloc(sizeof(char) * (len + 1));
}