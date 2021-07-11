#include "ft.h"

// REMOVE
#include <stdio.h>

int	ft_same(t_tab *tab, int x, int y)
{
	int	i;
	int	n;

	n = tab->inner[x][y];
	if (n == 0)
		return (0);
	i = x - 1;
	while (i >= 0)
		if (tab->inner[i--][y] == n)
			return (1);
	i = y - 1;
	while (i >= 0)
		if (tab->inner[x][i--] == n)
			return (1);
	return (0);
}

int	ft_valid(t_tab *tab, int x, int y)
{
	int	x_backward;
	int	x_forward;
	int	y_upward;
	int	y_downward;

	if (ft_same(tab, x, y))
		return (0);
	x_forward = ft_count_x_forward(tab, y);
	if (x_forward && x_forward != tab->outer[LEFT][y])
		return (0);
	x_backward = ft_count_x_backward(tab, y);
	if (x_backward && x_backward != tab->outer[RIGHT][y])
		return (0);
	y_upward = ft_count_y_upward(tab, x);
	if (y_upward && y_upward != tab->outer[BOTTOM][x])
		return (0);
	y_downward = ft_count_y_downward(tab, x);
	if (y_downward && y_downward != tab->outer[TOP][x])
		return (0);
	return (1);
}

int	ft_solve(t_tab *tab, int n)
{
	int	i;
	int	x;
	int	y;
	int	t;

	if (n == tab->size * tab->size)
	{
		printf("found solution\n");
		return (1);
	}
		
	i = 0;
	x = n % tab->size;
	y = n / tab->size;
	while (i < tab->size)
	{
		t = tab->inner[x][y];
		tab->inner[x][y] = i + 1;
		if (ft_valid(tab, x, y))
		{
			if (ft_solve(tab, n + 1))
				return (1);
		}
		tab->inner[x][y] = t;
		i++;
	}
	return (0);
}