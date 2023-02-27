/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:52:36 by sacorder          #+#    #+#             */
/*   Updated: 2023/02/22 18:38:06 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	str_char_cat(char *str, char chr)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
			++i;
	str[i] = chr;
	str[i + 1] = '\0';
}

int	ft_atoi(char *str)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - '0';
		++i;
	}
	return (nbr);
}

void	free_matrix(char **matrix, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(matrix[i]);
		++i;
	}
	free(matrix);
}

char	**alloc_matrix(int fd, int *line_length, int *line_nbr)
{
	char	byte;
	char	**matrix;
	int		p;
	char	*str;

	p = 0;
	str = (char *) malloc(sizeof(char) * 11);
	matrix = ((void *) 0);
	read(fd, &byte, 1);
	while (byte >= '0' && byte <= '9')
	{
		str_char_cat(str, byte);
		read(fd, &byte, 1);
	}
	*line_nbr = ft_atoi(str);
	if (*line_nbr > 0)
	{
		matrix = (char **) malloc(sizeof(char *) * *line_nbr);
		while (byte != '\n')
			read(fd, &byte, 1);
		read(fd, &byte, 1);
		while (byte != '\n')
		{
			++(*line_length);
			read(fd, &byte, 1);
		}
		while (p < *line_nbr)
		{
			matrix[p] = (char *) malloc(sizeof(char) * *line_length);
			++p;
		}
		return (matrix);
	}
	else
		return (matrix);
}

int	copy_file_to_matrix(int fd, char **matrix, char *charset,
		int width, int height)
{
	char	byte;
	int		line_counter;
	int		column_counter;

	read(fd, &byte, 1);
	while (byte >= '0' && byte <= '9')
		read(fd, &byte, 1);
	column_counter = 0;
	line_counter = 0;
	while (byte != '\n' && column_counter < 3)
	{
		charset[column_counter] = byte;
		read(fd, &byte, 1);
		++column_counter;
	}
	if (column_counter != 3)
		return (0);
	while (line_counter < height)
	{
		column_counter = 0;
		while (column_counter < width)
		{
			read(fd, &byte, 1);
			if (byte != charset[0] && byte != charset[1] && byte != '\n')
				return (0);
			matrix[line_counter][column_counter] = byte;
			++column_counter;
		}
		++line_counter;
	}
	return (1);
}

char	**matrix_init_from_file(char *filepath, char *charset, int *width, int *height)
{
	int		fd;
	char	**matrix;

	fd = open(filepath, O_RDONLY);
	*width = 1;
	if (fd < 0)
		return ((void *) 0);
	matrix = alloc_matrix(fd, width, height);
	if (matrix == (void *) 0)
		return (matrix);
	close(fd);
	fd = open(filepath, O_RDONLY);
	if (copy_file_to_matrix(fd, matrix, charset, *width, *height) == 0)
	{
		close(fd);
		free_matrix(matrix, *height);
		return ((void *) 0);
	}
	close(fd);
	return (matrix);
}
