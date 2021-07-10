#include <stdlib.h>
#include "ft.h"

int	ft_alloc_inner(t_tab *tab)
{
	int	i;
	
	tab->inner = malloc(tab->size * sizeof(int *));
	if (!tab->inner)
		return (0);
	i = 0;
	while (i < tab->size)
	{
		tab->inner[i] = malloc(tab->size * sizeof(int));
		if (!tab->inner[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_alloc_outer(t_tab *tab)
{
	int	i;

	tab->outer = malloc(4 * sizeof(int *));
	if (!tab->outer)
		return (0);
	i = 0;
	while (i < 4)
	{
		tab->outer[i] = malloc(tab->size * sizeof(int));
		if (!tab->outer[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_split2(char *str, int length, t_tab *tab)
{
	int		i;
	int		number;
	int		face;
	int		index;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		number = str[i] - '0';
		if (number > tab->size)
			return (0);
		face = (i / 2) / tab->size;
		index = (i / 2) % tab->size;
		tab->outer[face][index] = number;
		if (i < (length - 1))
		{
			if (str[i + 1] != ' ')
				return (0);
			i++;
		}
		i++;
	}
	return (1);
}

int	ft_split(char *str, t_tab *tab)
{
	int		i;
	int		length;
	int		count;

	length = 0;
	while (str[length])
		length++;
	if (length % 2 == 0)
		return (0);
	count = (length / 2) + 1;
	if (count % 4 != 0)
		return (0);
	if (count / 4 > 9)
		return (0);
	tab->size = count / 4;
	if (!ft_alloc_inner(tab))
		return (0);
	if (!ft_alloc_outer(tab))
		return (0);
	if (!ft_split2(str, length, tab))
		return (0);
	return (1);
}
