/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:32:30 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/24 10:47:34 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dup_element(char *elem, t_cub3d_data *data)
{
	printf(RED_DOT);
	printf(" Error\n");
	printf("[x] invalid or duplicated element: %s\n", elem);
	free_data(data);
	free(data);
	exit(301);
}

void	invalid_char(char chr, t_cub3d_data *data)
{
	printf(RED_DOT);
	printf(" Error\n");
	printf("[x] found invalid char in map: %c\n", chr);
	free_data(data);
	free(data);
	exit(301);
}

void	exiterr(char *error_text, t_cub3d_data *data, int errcode)
{
	printf(RED_DOT);
	printf(" Error\n");
	printf("[x] %s\n", error_text);
	if (errcode != 101 && errcode != 1)
	{
		free_data(data);
		free(data);
	}
	exit(errcode);
}

void	exitperror(t_cub3d_data *data, int errcode)
{
	printf(RED_DOT);
	printf(" Error\n");
	if (errcode == ERR_OPEN)
		perror("open");
	free_data(data);
	free(data);
	exit(EXIT_FAILURE);
}
