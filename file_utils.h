/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:47:13 by sacorder          #+#    #+#             */
/*   Updated: 2023/02/22 18:39:35 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FILE_UTILS_H
# define FILE_UTILS_H

int		ft_atoi(char *str);
void	free_matrix(char **matrix, int height);
char	**alloc_matrix(int fd, int *line_length, int *line_nbr);
int		copy_file_to_matrix(int fd, char ** matrix, char *charset, int width);
char	**matrix_init_from_file(char *filepath, char *charset, int *width, int *height);
#endif
