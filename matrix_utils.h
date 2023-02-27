/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:45:51 by sacorder          #+#    #+#             */
/*   Updated: 2023/02/22 18:40:29 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MATRIX_UTILS_H
# define MATRIX_UTILS_H

void	draw_square(char **matrix, char *charset, int x, int y, int size);
int		check_square(char **matrix, char *charset, int i, int j, int x, int y);
int		max_square_in_pos(char **matrix, int x, int y, char *charset);
void	print_matrix(char **matrix, int width, int height);
void	draw_biggest_square(char **matrix, int width, int height,
			char *charset);
#endif
