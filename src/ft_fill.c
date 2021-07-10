#include "ft.h"

// REMOVE
#include <stdio.h>

int	*ft_pos(t_tab *tab, int face, int index, int i)
{
	if (face == TOP)
		return &(tab->inner[index][i]);
	if (face == BOTTOM)
		return &(tab->inner[index][tab->size - 1 - i]);
	if (face == LEFT)
		return &(tab->inner[i][index]);
	if (face == RIGHT)
		return &(tab->inner[tab->size - 1 - i][index]);
	return (0);
}

void	ft_fill_line(t_tab *tab, int face, int index)
{
	int	i;
	int	*pos;

	i = 0;
	while (i < tab->size)
	{

		pos = ft_pos(tab, face, index, i);
		*pos = i + 1;
		i++;
	}
}

int	ft_fill_face(t_tab *tab, int face, int opposite)
{
	int index;
	int	n;
	int	m;

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
		index++;
	}
	return (1);
}

int	ft_fill(t_tab *tab)
{
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