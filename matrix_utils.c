/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:43:54 by sacorder          #+#    #+#             */
/*   Updated: 2023/02/22 18:28:09 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	draw_square(char **matrix, char *charset, int x, int y, int size)
{
	int	i;
	int	j;

	j = y;
	while (j > y - size)
	{
		i = x;
		while (i > x - size)
		{
			matrix[j][i] = charset[2];
			--i;
		}
		--j;
	}
}

int	check_square(char **matrix, char *charset, int i, int j, int x, int y)
{
	int	tmp;

	tmp = j;
	while (tmp <= y)
	{
		if (matrix[tmp][i] == charset[1])
				return (1);
		++tmp;
	}
	tmp = i;
	while (tmp <= x)
	{
		if (matrix[j][tmp] == charset[1])
				return (1);
		++tmp;
	}
	return (0);
}

int	max_square_in_pos(char **matrix, int x, int y, char *charset)
{
	int	i;
	int	j;
	int	hit;

	if (matrix[y][x] != charset[0])
		return (0);
	i = x;
	j = y;
	hit = 0;
	while (i >= 0 && j >= 0 && hit == 0)
	{
		hit = check_square(matrix, charset, i, j, x, y);
		--j;
		--i;
	}
	if(hit != 1)
		return (x - i);
	return (x - i - 1);
}

void	print_matrix(char **matrix, int width, int height)
{
	int		i;
	int		j;

	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			write(1, " ", 1);
			write(1, &matrix[j][i], 1);
			++i;
		}
		++j;
	}
}

void	draw_biggest_square(char **matrix, int width, int height, char *charset)
{
	int	x;
	int	y;
	int	max;
	int	current_pos_size;
	int	i;
	int	j;

	j = 0;
	max = 0;
	while (j < height)
	{
		i = 0;
		while (i < width - 1)
		{
			current_pos_size = max_square_in_pos(matrix, i, j, charset);
			if (max < current_pos_size)
			{
				x = i;
				y = j;
				max = current_pos_size;
			}
			++i;
		}
		++j;
	}
	draw_square(matrix, charset, x, y, max);
}
