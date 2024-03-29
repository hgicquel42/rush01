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
	if (!ft_solve(&tab, 0))
		return (ft_main_err());
	ft_puttab(&tab);
	ft_free(&tab);
	return (0);
}
