int		count_visible(int *line);
void	get_col(int result[4][4], int col[4], int i);

void	fill_row_rev(int result[4][4], int rev_row[], int i)
{
	rev_row[0] = result[i][3];
	rev_row[1] = result[i][2];
	rev_row[2] = result[i][1];
	rev_row[3] = result[i][0];
}

int	check_inputs(int result[4][4], int *inputs)
{
	int	col[4];
	int	rev_row[4];
	int	rev_col[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		if (inputs[8 + i] && count_visible(result[i]) != inputs[8 + i])
			return (0);
		fill_row_rev(result, rev_row, i);
		if (inputs[12 + i] && count_visible(rev_row) != inputs[12 + i])
			return (0);
		get_col(result, col, i);
		if (inputs[i] && count_visible(col) != inputs[i])
			return (0);
		rev_col[0] = col[3];
		rev_col[1] = col[2];
		rev_col[2] = col[1];
		rev_col[3] = col[0];
		if (inputs[4 + i] && count_visible(rev_col) != inputs[4 + i])
			return (0);
		i++;
	}
	return (1);
}

int	check_row_col(int i, int j, int result[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		if (row != i && result[row][j] == result[i][j])
		{
			return (0);
		}
		row++;
	}
	col = 0;
	while (col < 4)
	{
		if (col != j && result[i][col] == result[i][j])
		{
			return (0);
		}
		col++;
	}
	return (1);
}
