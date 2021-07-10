#include "ft.h"

// REMOVE
#include <stdio.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

t_pos	ft_pos_abs(int x, int y)
{
	t_pos pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

t_pos ft_pos_rel(int face, int index, int i, int max)
{
	if (face == TOP)
		return (ft_pos_abs(index, i));
	if (face == BOTTOM)
		return (ft_pos_abs(index, max - 1 - i));
	if (face == LEFT)
		return (ft_pos_abs(i, index));
	if (face == RIGHT)
		return (ft_pos_abs(max - 1 - i, index));
	return (ft_pos_abs(0, 0));
}

int	*ft_pos2(t_tab *tab, int face, int index, int i)
{
	t_pos	pos;
	
	pos = ft_pos_rel(face, index, i, tab->size);
	return &(tab->inner[pos.x][pos.y]);
}

void	ft_fill_line(t_tab *tab, int face, int index)
{
	int	i;
	t_pos pos;

	i = 0;
	while (i < tab->size)
	{
		t_pos pos = ft_pos_rel(face, index, i, tab->size);
		tab->inner[pos.x][pos.y] = i + 1;
		i++;
	}
}

int	ft_fill_face(t_tab *tab, int face, int opposite)
{
	int index;
	t_pos	pos;
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
		if (n == 1)
		{
			pos = ft_pos_rel(face, index, 0, tab->size);
			tab->inner[pos.x][pos.y] = tab->size;
		}
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
		{
			tab->inner[x][y] = 0;
			y++;
		}
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