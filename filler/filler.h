#ifndef FILLER_H
#define FILLER_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFF_SIZE 50

typedef struct list
{
	char		*str;
	int			nl;
	int			len;
	struct list	*next;
} list;

list	*createNewList(void);
void	addNewElement(const list *head);
void	appendListAtTheEnd(const list *head, const list *new);

void	ftStrCpy(char *dst, char *src);
int		ftStrLen(const char *str);
void	ft_nbzero(char *str, int last_index);
void	ftBZero(char *str);

list	*readAllInput(void);
void    fillListWithData(list *list, int readed, char *buf);
int		ftNlCounter(const char *str);

#endif
