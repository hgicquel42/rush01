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

void	ft_putchar(char	c);

void	ft_putnbr(int n);

void	ft_putstr(char	*str);

void	ft_puterr(char	*str);

void	ft_puttab(t_tab *tab);

int		ft_split(char *str, t_tab *tab);

int		ft_fill(t_tab *tab);

int		ft_solve(t_tab *tab, int x);

int		ft_count_y_upward(t_tab *tab, int y);

int		ft_count_y_downward(t_tab *tab, int y);

int		ft_count_x_forward(t_tab *tab, int x);

int		ft_count_x_backward(t_tab *tab, int x);

#endif