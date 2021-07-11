#include "ft.h"

t_pos	ft_pos_abs(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

t_pos	ft_pos_rel(int face, int index, int i, int max)
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

int	*ft_get_pos(t_tab *tab, int face, int index, int i)
{
	t_pos	pos;

	pos = ft_pos_rel(face, index, i, tab->size);
	return (&(tab->inner[pos.x][pos.y]));
}
