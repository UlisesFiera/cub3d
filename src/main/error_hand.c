/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:32:30 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/20 15:57:33 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exiterr(char *error_text, t_mlx_data *mlx, int errcode)
{
	printf(RED_DOT);
	printf(" %s\n", error_text);
	if (errcode != 101)
		free_mlx(mlx);
	exit(errcode);
}
