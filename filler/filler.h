#ifndef FILLER_H
#define FILLER_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFF_SIZE 150

typedef struct list
{
	char		*str;
	int			nl;
	int			len;
	struct list	*next;
} list;

list	*create_new_list(void);
void	add_new_element(const list *head);
void	append_list_at_the_end(const list *head, const list *new);
void	ft_free_element(list *list_for_free);

void	ft_strcpy(char *dst, char *src);
int		ft_strlen(const char *str);
void	ft_nbzero(char *str, int last_index);
void	ft_bzero(char *str);
int		ft_strstr(char *where, char *what);

list	*read_all_input(void);
void    fill_list_with_data(list *list, int readed, char *buf);
int		ft_nl_counter(const char *str);

#endif
