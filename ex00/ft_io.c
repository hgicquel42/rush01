#include <unistd.h>
#include "ft.h"

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	ft_putstr(char	*str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_puterr(char	*str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_puttab(t_tab *tab)
{
	int	x;
	int	y;

	y = 0;
	while (y < tab->size)
	{
		x = 0;
		while (x < tab->size)
		{
			ft_putchar('0' + tab->inner[x++][y]);
			if (x < tab->size)
				ft_putchar(' ');
		}		
		ft_putchar('\n');
		y++;
	}
}
