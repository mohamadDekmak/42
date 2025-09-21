#include <unistd.h>

void	copy_line(int *dest, int *src);
int		is_unique(int result[4][4]);
int		check_inputs(int result[4][4], int *inputs);
void	print_result(int result[4][4]);

int	check_and_print(int result[4][4], int *inputs)
{
	if (is_unique(result) && check_inputs(result, inputs))
	{
		print_result(result);
		return (1);
	}
	return (0);
}

void	fill_row3_4(int result[4][4], int all_combinations[24][4], int c, int d)
{
	copy_line(result[2], all_combinations[c]);
	copy_line(result[3], all_combinations[d]);
}

int	help(int result[4][4], int all_combinations[24][4], int a, int *inputs)
{
	int	c;
	int	d;
	int	b;

	b = 0;
	while (b < 24)
	{
		c = 0;
		while (c < 24)
		{
			d = 0;
			while (d < 24)
			{
				copy_line(result[0], all_combinations[a]);
				copy_line(result[1], all_combinations[b]);
				fill_row3_4(result, all_combinations, c, d);
				if (check_and_print(result, inputs))
					return (1);
				d++;
			}
			c++;
		}
		b++;
	}
	return (0);
}

void	fill_result(int result[4][4], int all_combinations[24][4], int *inputs)
{
	int	a;
	int	x;

	a = 0;
	while (a < 24)
	{
		x = help(result, all_combinations, a, inputs);
		if (x)
		{
			return ;
		}
		a++;
	}
	if (!x)
		write(1, "Error\n", 6);
}
