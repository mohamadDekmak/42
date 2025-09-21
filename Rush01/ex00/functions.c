#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_result(int result[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(result[i][j] + '0');
			if (j < 3)
			{
				ft_putchar(' ');
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	get_col(int result[4][4], int col[4], int i)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		col[j] = result[j][i];
		j++;
	}
}

int	count_visible(int *line)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}
