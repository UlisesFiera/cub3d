/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:32:30 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/20 17:23:17 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exiterr(char *error_text, t_cub3d_data *data, int errcode)
{
	printf(RED_DOT);
	printf(" %s\n", error_text);
	if (errcode != 101)
		free_mlx(data);
	exit(errcode);
}

void	exitperror(t_cub3d_data *data, int errcode)
{
	printf(RED_DOT);
	if (errcode == E_OPEN)
		perror("open");
	free_mlx(data);
	exit(EXIT_FAILURE);
}
