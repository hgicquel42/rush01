#include "ft.h"
#include <stdio.h>

int	ft_main_err()
{
	ft_puterr("Error\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_tab	tab;
	
	if (argc != 2)
		return (ft_main_err());
 	ft_split(argv[1], &tab);
	if (!tab.size)
		return (ft_main_err());
	return (0);
}