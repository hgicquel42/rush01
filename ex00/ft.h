#ifndef FT_H
# define FT_H

# define TOP 0
# define BOTTOM 1
# define LEFT 2
# define RIGHT 3

typedef struct s_tab
{
	int	**outer;
	int	**inner;
	int	size;
}	t_tab;

int		ft_split(char *str, t_tab *tab);

int		ft_fill(t_tab *tab);

int		ft_solve(t_tab *tab, int x);

void	ft_puttab(t_tab *tab);

void	ft_putchar(char	c);

void	ft_putnbr(int n);

void	ft_putstr(char	*str);

void	ft_puterr(char	*str);

#endif