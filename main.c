/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:42:59 by sacorder          #+#    #+#             */
/*   Updated: 2023/02/22 18:41:06 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "matrix_utils.h"
#include "file_utils.h"

int	print_file_error(void)
{
	write(1, "map error\n", 10);
	return (1);
}

int	parse_first_line(char *line, int *height, char *charset)
{
	int		i;
	int		counter;
	char	*tmp;

	i = 0;
	counter = 0;
	tmp = (char *) malloc(sizeof(char) * 11);
	tmp[0] = '\0';
	while (line[i] >= '0' && line[i] <= '9')
	{	
		tmp[i] = line[i];
		++i;
	}
	tmp[i] = '\0';
	*height = ft_atoi(tmp);
	if (*height <= 0)
		return (0);
	while (counter < 3)
	{
		charset[counter] = line[i];
		++counter;
		++i;
	}
	if (line[i] != '\n')
		return (0);
	return (1);
}

int	parse_map_from_stdin(char **matrix, int *width, int height, char *charset)
{
	int		p;
	char	*byte;
	int		i;

	p = 0;
	*width = 0;
	byte = (char *) malloc(sizeof(char) * 400);
	matrix = (char **) malloc(sizeof(char *) * height);
	if (matrix == (void *) 0)
		return (0);
	read(0, byte, 400);
	while (byte[*width] != '\n')
		++(*width);
	++(*width);
	while (p < height)
	{
		matrix[p] = (char *) malloc(sizeof(char) * *width);
		++p;
	}
	p  = 0;
	while (p < *width)
	{
		matrix[0][p] = byte[p];
		++p;
	}
	p = 1;
	while (p < height)
	{
		i = 0;
		read(0, matrix[p], *width);
		while (i < *width - 1)
		{
			if (matrix[p][i] != charset[0] && matrix[p][i] != charset[1])
				return (0);
			++i;
		}
		if (matrix[p][*width - 1] != '\n')
			return (0);
		++p;
	}
	free(byte);
	draw_biggest_square(matrix,*width, height, charset);
	print_matrix(matrix, *width, height);
	free_matrix(matrix, height);	
	return(1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**matrix;
	int		width;
	int		height;
	char	*charset;
	char	*line;

	i = 1;
	charset = (char *) malloc(sizeof(char) * 3);
	matrix  = ((void *) 0);
	width = 0;
	if (argc == 1)
	{
		line = (char *) malloc(sizeof(char) * 14);
		read(1, line, 14);
		if (parse_first_line(line, &height, charset) == 0)
			return (print_file_error());
		if (parse_map_from_stdin(matrix, &width, height, charset) == 0)
			return(print_file_error());
		return (0);
	}
	else
	{
		while (i < argc)
		{
			matrix = matrix_init_from_file(argv[i], charset, &width, &height);
			if (matrix == (void *) 0)
				print_file_error();
			else
			{
				draw_biggest_square(matrix, width, height, charset);
				print_matrix(matrix, width, height);
				free_matrix(matrix, height);
			}
			++i;
		}
	}
	free(charset);
	return (0);
}
