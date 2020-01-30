#include "filler.h"

list	*create_new_list(void)
{
	list	*new;

	new = (list*)malloc(sizeof(list));
	new->len = 0;
	new->nl = 0;
	new->str = NULL;
	new->next = NULL;
	return (new);
}

void	add_new_element(const list *head)
{
	list	*new;
	list	*tmp;

	tmp = (list*)head;
	new = create_new_list();
	while (tmp->next != NULL)
		tmp = head->next;
	tmp->next = new;
}

void	append_list_at_the_end(const list *head, const list *new)
{
	list	*tmp;

	tmp = (list*)head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (list*)new;
}

void	ft_free_element(list *list_for_free)
{
	ft_bzero(list_for_free->str);
	list_for_free->len = 0;
	list_for_free->nl = 0;
	list_for_free->next = NULL;
	free(list_for_free->str);
	free(list_for_free);
	list_for_free = NULL;
}
