#include "filler.h"

list	*readAllInput(void)
{
	char	*buf;
	int		readed;
	list	*head;
	list	*tmp;

	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_nbzero(buf, BUFF_SIZE);
	// for (int i = 0; i <= BUFF_SIZE; i++)
	// 	buf[i] = '\0';
	// buf[BUFF_SIZE] = '\0';
	head = createNewList();
	readed = read(0, buf, BUFF_SIZE);
	fillListWithData(head, readed, buf);
	while (readed != 0)
	{
		if ((readed = read(0, buf, BUFF_SIZE)) != 0)
		{
			tmp = createNewList();
			fillListWithData(tmp, readed, buf);
			appendListAtTheEnd(head, tmp);
			ftBZero(buf);
		}
	}
	if (head->len != 0)
		return (head);
	free (head->str);
	free (head);
	free (buf);
	return (NULL);
}

void    fillListWithData(list *list, int readed, char *buf)
{
	int i;

	i = -1;
	list->len = readed;
	list->str = (char*)malloc(sizeof(char) * (readed + 1));
	while (++i <= readed)
		(list->str)[i] = '\0';
	ftStrCpy(list->str, buf);
	list->nl = ftNlCounter(list->str);
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

