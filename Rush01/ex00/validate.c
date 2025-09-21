int	check_row_col(int i, int j, int result[4][4]);

int	ft_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 31)
		return (0);
	i = 0;
	while (i < 31)
	{
		if (i % 2 == 0)
		{
			if (!(str[i] >= '1' && str[i] <= '4'))
				return (0);
		}
		else
		{
			if (!(str[i] == ' '))
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

void	copy_line(int *dest, int *src)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		dest[i] = src[i];
		i++;
	}
}

int	is_unique(int result[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (!check_row_col(i, j, result))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
