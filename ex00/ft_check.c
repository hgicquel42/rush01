#include "ft.h"

// REMOVE
#include <unistd.h>
#include <stdio.h>

int	ft_count_y_upward(t_tab *tab, int y)
{
	int	i;
	int	count;
	int	height;

	i = 0;
	count = 0;
	height = 0;
	while (i < tab->size)
	{
		if (!tab->inner[i][y])
			return (0);
		if (tab->inner[i][y] > height)
		{
			height = tab->inner[i][y];
			count++;
		}
		i++;
	}	
	return (count);
}

int	ft_count_y_downward(t_tab *tab, int y)
{
	int	i;
	int	count;
	int	height;

	i = tab->size - 1;
	count = 0;
	height = 0;
	while (i > 0)
	{
		if (!tab->inner[i][y])
			return (0);
		if (tab->inner[i][y] > height)
		{
			height = tab->inner[i][y];
			count++;
		}
		i--;
	}
	return (count);
}

int	ft_count_x_forward(t_tab *tab, int x)
{
	int	i;
	int	count;
	int	height;

	i = 0;
	count = 0;
	height = 0;
	while (i < tab->size)
	{
		if (!tab->inner[x][i])
			return (0);
		if (tab->inner[x][i] > height)
		{
			height = tab->inner[x][i];
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_count_x_backward(t_tab *tab, int x)
{
	int	i;
	int	count;
	int	height;

	i = tab->size - 1;
	count = 0;
	height = 0;
	while (i > 0)
	{
		if (!tab->inner[x][i])
			return (0);
		if (tab->inner[x][i] > height)
		{
			height = tab->inner[x][i];
			count++;
		}
		i--;
	}	
	return (count);
}