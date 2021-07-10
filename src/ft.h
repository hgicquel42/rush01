#ifndef FT_H
# define FT_H

typedef struct s_tab
{
	int	**outer;
	int	**inner;
	int	size;
}	t_tab;

int		ft_split(char *str, t_tab *tab);

void	ft_putstr(char	*str);

void	ft_puterr(char	*str);

#endif