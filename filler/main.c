#include "filler.h"

int main(void)
{
	list	*new;
	int		i;

	new = read_all_input();
	i = 1;
	while (new != NULL)
	{
		if (ft_strstr(new->str, "Plateau\0") == 0)
		{
			printf("find at %d chain\n", i);
			puts(new->str);
			break ;
		}
		new = new->next;
		i++;
	}
	return (0);
}
