#ifndef FILLER_H
#define FILLER_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFF_SIZE 10

typedef struct list
{
	char		*str;
	int			nl;
	int			len;
	struct list	*next;
} list;

void	readMap(void);

#endif
