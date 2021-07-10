typedef struct s_tab
{
	int	*array;
	int	size;
}	t_tab;

void	ft_split(char *str, t_tab *result);

void	ft_putstr(char	*str);

void	ft_puterr(char	*str);