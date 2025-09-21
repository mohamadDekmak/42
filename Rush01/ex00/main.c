#include <unistd.h>

int		ft_valid(char *str);
void	generate_combinations(int T[24][4]);
void	fill_result(int result[4][4], int all_combinations[24][4], int *inputs);

int	main(int argc, char **argv)
{
	int	inputs[16];
	int	j;
	int	i;
	int	result[4][4];
	int	all_combinations[24][4];

	if (argc != 2 || !ft_valid(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	j = 0;
	i = 0;
	while (i < 31)
	{
		inputs[j++] = argv[1][i] - 48;
		i += 2;
	}
	generate_combinations(all_combinations);
	fill_result(result, all_combinations, inputs);
	return (0);
}
