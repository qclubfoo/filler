#include "filler.h"

list	*createNewList(void)
{
	list	*new;

	new = (list*)malloc(sizeof(list));
	new->len = 0;
	new->nl = 0;
	new->str = NULL;
	new->next = NULL;
	return (new);
}

void	addNewElement(const list *head)
{
	list	*new;
	list	*tmp;

	tmp = (list*)head;
	new = createNewList();
	while (tmp->next != NULL)
		tmp = head->next;
	tmp->next = new;
}

void	appendListAtTheEnd(const list *head, const list *new)
{
	list	*tmp;

	tmp = (list*)head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (list*)new;
}

void	ftStrCpy(char *dst, char *src)
{
	int i;

	i = -1;
	while (src[++i] != '\0')
		dst[i] = src[i];
}

int		ftNlCounter(const char *str)
{
	int	nl;
	int	i;

	nl = 0;
	i = -1;
	while (str[++i] != '\0')
		str[i] == '\n' ? nl++ : 0;
	return (nl);
}

// int		ftStrLen(const char *str)
// {
// 	int len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// }

void	ftBZero(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
}

list	*gnl(void)
{
	char	*buf;
	int		readed;
	list	*head;
	list	*tmp;

	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	buf[BUFF_SIZE] = '\0';
	head = createNewList();
	readed = read(0, buf, BUFF_SIZE);
	head->len = readed;
	head->str = (char*)malloc(sizeof(char) * (readed + 1));
	(head->str)[readed] = '\0';
	ftStrCpy(head->str, buf);
	head->nl = ftNlCounter(head->str);
	while (readed != 0)
	{
		readed = read(0, buf, BUFF_SIZE);
		tmp = createNewList();
		tmp->str = (char*)malloc(sizeof(char) * (readed + 1));
		(tmp->str)[readed] = '\0';
		tmp->len = readed;
		ftStrCpy(tmp->str, buf);
		tmp->nl = ftNlCounter(tmp->str);
		appendListAtTheEnd(head, tmp);
		tmp = NULL;
		ftBZero(buf);
	}
	if (head->len != 0)
		return (head);
	else
		return (NULL);
}



int main(void)
{
	list	*new;

	new = gnl();
	if (new == NULL)
		printf("new == NULL\n");
	while (new != NULL)
	{
		printf("str = %s", new->str);
		new = new->next;
	}
	return (0);
}
