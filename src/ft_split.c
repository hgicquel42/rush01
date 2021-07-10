#include <stdlib.h>
#include "ft.h"

void	ft_split(char *str, t_tab *tab)
{
	int		i;
	int		j;
	int		length;
	t_tab 	result;

	length = 0;
	while (str[length])
		length++;
	if (length % 2 == 0)
		return ;
	result.size = (length / 2) + 1;
	if (result.size % 4 != 0)
		return ;
	result.array = malloc(result.size * sizeof(int));

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return ;
		result.array[j] = str[i] - '0';
		if (i < (length - 1))
		{
			if (str[i + 1] != ' ')
				return ;
			i++;
		}
		i++;
		j++;
	}
	*tab = result;
}