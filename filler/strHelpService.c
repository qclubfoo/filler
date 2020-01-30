#include "filler.h"

void	ftStrCpy(char *dst, char *src)
{
	int i;

	i = -1;
	while (src[++i] != '\0')
		dst[i] = src[i];
}

int		ftStrLen(const char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_nbzero(char *str, int last_index)
{
	int	i;

	i = -1;
	while (++i <= last_index)
		str[i] = '\0';
}

void	ft_bzero(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		str[i] = '\0';
}

int		ft_strcmp(char *where, char *what)
{
	int i;
	int	j;

	if (where[0] == '\0')
		return (0);
	i = -1;
	while (where[++i] != '\0')
	{
		j = 0;
		while(what[j] == where[i + j])
			j++;
		if (where[i + j] == '\0' && what[j] == '\0')
			return (0);
		if (where[i + j] == '\0' && what[j] != '\0')
			return (-1);
		if (what[j] == '\0')
			return (0);
	}
	return (-1);
}

