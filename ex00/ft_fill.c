#include "ft.h"

void	ft_fill_line(t_tab *tab, int face, int index)
{
	int		i;

	i = 0;
	while (i < tab->size)
	{
		*ft_get_pos(tab, face, index, i) = i + 1;
		i++;
	}
}

int	ft_fill_face(t_tab *tab, int face, int opposite)
{
	int		index;
	int		n;
	int		m;

	index = 0;
	while (index < tab->size)
	{
		n = tab->outer[face][index];
		m = tab->outer[opposite][index];
		if (n + m > tab->size + 1)
			return (0);
		if (n == tab->size)
		{
			if (m != 1)
				return (0);
			ft_fill_line(tab, face, index);
		}
		if (n == 1)
			*ft_get_pos(tab, face, index, 0) = tab->size;
		index++;
	}
	return (1);
}

int	ft_fill(t_tab *tab)
{
	int	x;
	int	y;

	x = 0;
	while (x < tab->size)
	{
		y = 0;
		while (y < tab->size)
			tab->inner[x][y++] = 0;
		x++;
	}
	if (!ft_fill_face(tab, TOP, BOTTOM))
		return (0);
	if (!ft_fill_face(tab, BOTTOM, TOP))
		return (0);
	if (!ft_fill_face(tab, LEFT, RIGHT))
		return (0);
	if (!ft_fill_face(tab, RIGHT, LEFT))
		return (0);
	return (1);
}
