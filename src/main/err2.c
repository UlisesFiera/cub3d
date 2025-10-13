/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:31:21 by ulfernan          #+#    #+#             */
/*   Updated: 2025/10/13 15:40:51 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bad_color(t_cub3d_data *data, char *number)
{
	printf("Error\n");
	printf(RED_DOT);
	printf(" invalid or missing color value\n");
	free(number);
	free_data(data);
	exit(301);
}

void	dup_dir_element(t_cub3d_data *data)
{
	printf("Error\n");
	printf(RED_DOT);
	printf(" player orientation character duplicated\n");
	free_data(data);
	exit(301);
}

void	no_dir_found(t_cub3d_data *data)
{
	printf("Error\n");
	printf(RED_DOT);
	printf(" player orientation character not found\n");
	free_data(data);
	exit(301);
}
