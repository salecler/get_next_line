#include "get_next_line.h"
#include <fcntl.h>

char    *get_next_line(int fd)
{    
    static t_list *stash = NULL;
    char                  *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = NULL;
    read_and_stash(fd, &stash);
    if (stash == NULL)
        return (NULL);
    add_to_line(stash, &line);
    clean_stash(&stash);
    if (line[0] == '\0')
    {
        free_stash(stash);
        stash = NULL;
        free(line);
        return (NULL);
    }
    return (line);
}

void    read_and_stash(int fd, t_list **stash)
{
    char    *buff;
    int     readed;
    
	readed = 1;
    while (!(found_nl(*stash)) && readed != 0)
    {
        buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buff)
            return;
		readed = read(fd, buff, BUFFER_SIZE);
        if (*stash == NULL && (readed == 0 || readed == -1))
        {
            free(buff);
            return;
        }
        buff[readed] = '\0';
        add_to_stash(stash, &buff, readed);
        free(buff);
    }
}

void    add_to_stash(t_list **stash, char **buff, int readed)
{
    int     i;
    t_list  *last;
    t_list  *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return;
    new_node->next = NULL;
    new_node->content = malloc(sizeof(char) * (readed + 1));
    if (new_node->content == NULL)
        return;
    i = 0;
    while (i < readed)
    {
        new_node->content[i] = (*buff)[i];
        i++;
    }
    new_node->content[i] = '\0';
    if (*stash == NULL)
    {
        *stash = new_node;
        return;
    }
    last = ft_lst_get_last(*stash);
    last->next = new_node;
}

void    add_to_line(t_list *stash, char **line)
{
    int i;
    int j;

    if (stash == NULL)
        return;
    generate_line(line, stash);
    if (*line == NULL)
        return;
    j = 0;
    while (stash)
    {
        i = 0;
        while (stash->content[i])
        {
            if (stash->content[i] == '\n')
                {
                    (*line)[j] = stash->content[i];
                    j++;
                    break;
                }
            (*line)[j] = stash->content[i];
            j++;
            i++;
        }
        stash = stash->next;
    }
    (*line)[j] = '\0';
}

void    clean_stash(t_list **stash)
{
    t_list  *last;
    t_list  *clean_node;
    int i;
    int j;

    clean_node = malloc(sizeof(t_list));
    if (!clean_node)
        return;
    clean_node->next = NULL;
    last = ft_lst_get_last(*stash);
    i = 0;
    while (last->content[i] && last->content[i] != '\n')
        i++;
    if (last->content[i] && last->content[i] == '\n')
        i++;
    clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
    if (clean_node->content == NULL)
        return;
    j = 0;
    while (last->content[i])
        clean_node->content[j++] = last->content[i++];
    clean_node->content[j] = '\0';
    free_stash(*stash);
    *stash = clean_node;
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	if(fd < 2)
		printf("error\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
