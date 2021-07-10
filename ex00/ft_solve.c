#include "ft.h"

int	ft_same(t_tab *tab, int x, int y)
{
	int	i;
	int	n;

	n = tab->inner[x][y];
	if (n == 0)
		return (0);
	// i = x + 1;
	// while (i < tab->size)
	// 	if (tab->inner[i++][y] == n)
	// 		return (1);
	i = x - 1;
	while (i > 0)
		if (tab->inner[i--][y] == n)
			return (1);
	// i = y + 1;
	// while (i < tab->size)
	// 	if (tab->inner[x][i++] == n)
	// 		return (1);
	i = y - 1;
	while (i > 0)
		if (tab->inner[x][i--] == n)
			return (1);
	return (0);
}

int	ft_valid(t_tab *tab, int x, int y)
{
	if (ft_same(tab, x, y))
		return (0);
	
	return (1);
}

int	ft_solve(t_tab *tab, int n)
{
	int	i;
	int	x;
	int	y;

	if (n == tab->size * tab->size)
		return (1);
	i = 0;
	x = n / tab->size;
	y = n % tab->size;
	while (i < tab->size)
	{
		tab->inner[x][y] = i + 1;
		if (ft_valid(tab, x, y))
		{
			if (ft_solve(tab, n + 1))
				return (1);
			tab->inner[x][y] = 0;
		}
		i++;
	}
	tab->inner[x][y] = 0;
	return (0);
}