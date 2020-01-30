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

void	ftBZero(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
}

