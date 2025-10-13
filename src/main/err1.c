/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:32:30 by ulfernan          #+#    #+#             */
/*   Updated: 2025/10/13 15:40:31 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dup_element(char *elem, t_cub3d_data *data)
{
	printf("Error\n");
	printf(RED_DOT);
	printf(" invalid or duplicated element: %s\n", elem);
	free_data(data);
	exit(301);
}

void	invalid_char(char chr, t_cub3d_data *data)
{
	printf("Error\n");
	printf(RED_DOT);
	printf(" found invalid char in map or color code: ");
	printf(RED);
	printf("%c\n", chr);
	printf(DEFAULT);
	free_data(data);
	exit(301);
}

void	openmaperr(char **map, int row, int col)
{
	int	i;
	int	j;

	printf("Error\n");
	printf(RED_DOT);
	printf(" Operture in map found at row %i col %i\n", row, col);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == row && j == col)
				printf("\033[31m%c\033[0m", map[i][j]);
			else
				printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	exiterr(char *error_text, t_cub3d_data *data, int errcode)
{
	printf("Error\n");
	printf(RED_DOT);
	printf(" [x] %s\n", error_text);
	if (errcode != 101 && errcode != 1)
		free_data(data);
	exit(errcode);
}

void	exitperror(t_cub3d_data *data, int errcode)
{
	printf("Error\n");
	printf(RED_DOT);
	if (errcode == ERR_OPEN)
		perror("open");
	free_data(data);
	exit(EXIT_FAILURE);
}
