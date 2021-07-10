#include <stdio.h>
#include "ft.h"

int	ft_main_err(void)
{
	ft_puterr("Error\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_tab	tab;

	if (argc != 2)
		return (ft_main_err());
	if (!ft_split(argv[1], &tab))
		return (ft_main_err());
	ft_fill(&tab);
	int x = 0;
	while (x < 4)
	{
		int y = 0;
		while (y < tab.size)
			printf("%d,", tab.inner[x][y++]);
		printf("\n");
		x++;
	}
	return (0);
}
