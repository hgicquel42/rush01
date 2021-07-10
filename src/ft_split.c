#include <stdlib.h>
#include "ft.h"

#include <stdio.h>

int	g_top = 0;
int	g_bottom = 1;
int	g_left = 2;
int	g_right = 3;

int	ft_split2(char *str, int length, t_tab *tab)
{
	int		i;
	int		x;
	int		y;
	int		n;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		n = str[i] - '0';
		if (n > tab->size)
			return (0);
		x = (i / 2) / tab->size;
		y = (i / 2) % tab->size;
		tab->outer[x][y] = n;
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
	tab->outer = malloc(4 * sizeof(int *));
	i = 0;
	while (i < 4)
		tab->outer[i++] = malloc(tab->size * sizeof(int));
	return (ft_split2(str, length, tab));
}
