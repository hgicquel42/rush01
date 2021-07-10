#include <stdio.h>
#include "ft.h"

int	ft_main_err(void)
{
	ft_puterr("Error\n");
	return (1);
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
			printf("%d ", tab->inner[x++][y]);  
		printf("\n");
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_tab	tab;

	if (argc != 2)
		return (ft_main_err());
	if (!ft_split(argv[1], &tab))
		return (ft_main_err());
	ft_fill(&tab);
	ft_puttab(&tab);
	return (0);
}
