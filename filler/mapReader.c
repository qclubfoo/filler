#include "filler.h"

list	*read_all_input(void)
{
	char	*buf;
	int		readed;
	list	*head;
	list	*tmp;

	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_nbzero(buf, BUFF_SIZE);
	head = create_new_list();
	readed = read(0, buf, BUFF_SIZE);
	fillListWithData(head, readed, buf);
	while (readed != 0)
	{
		if ((readed = read(0, buf, BUFF_SIZE)) != 0)
		{
			tmp = create_new_list();
			fillListWithData(tmp, readed, buf);
			append_list_at_the_end(head, tmp);
			ft_bzero(buf);
		}
	}
	if (head->len != 0)
		return (head);
	ft_free_element(head);
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

