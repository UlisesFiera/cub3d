/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:31:21 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/25 18:46:31 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bad_color(t_cub3d_data *data, char *number)
{
	printf(RED_DOT);
	printf(" Error\n");
	printf("[x] invalid or missing color value\n");
	free(number);
	free_data(data);
	free(data);
	exit(301);
}

void	dup_dir_element(t_cub3d_data *data)
{
	printf(RED_DOT);
	printf(" Error\n");
	printf("[x] player orientation character duplicated\n");
	free_data(data);
	free(data);
	exit(301);
}

void	no_dir_found(t_cub3d_data *data)
{
	printf(RED_DOT);
	printf(" Error\n");
	printf("[x] player orientation character not found\n");
	free_data(data);
	free(data);
	exit(301);
}