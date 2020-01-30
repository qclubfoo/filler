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