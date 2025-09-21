void	ft_fill(int a, int b, int *i, int T[24][4])
{
	int	d;
	int	c;

	c = 1;
	while (c <= 4)
	{
		d = 1;
		while (d <= 4)
		{
			if (a != b && a != c && a != d && b != c && b != d && c != d)
			{
				T[*i][0] = a;
				T[*i][1] = b;
				T[*i][2] = c;
				T[*i][3] = d;
				*i = *i + 1;
			}
			d++;
		}
		c++;
	}
}

void	generate_combinations(int T[24][4])
{
	int	a;
	int	b;
	int	i;

	i = 0;
	a = 1;
	while (a <= 4)
	{
		b = 1;
		while (b <= 4)
		{
			ft_fill(a, b, &i, T);
			b++;
		}
		a++;
	}
}
