/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalguer <asalguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/02 18:55:00 by asalguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_player *player)
{
    double	rot;
	double	old_dir_x;
    double	old_plane_x;

	rot = 0.0;
    if (player->rotate_left)
        rot -= player->rot_speed;
    if (player->rotate_right)
        rot += player->rot_speed;
    if (rot == 0.0)
        return ;
    old_dir_x = player->dir_x;
    old_plane_x = player->plane_vector_x;
    player->dir_x = player->dir_x * cos(rot) - player->dir_y * sin(rot);
    player->dir_y = old_dir_x * sin(rot) + player->dir_y * cos(rot);
    player->plane_vector_x = player->plane_vector_x * cos(rot) - \
							player->plane_vector_y * sin(rot);
    player->plane_vector_y = old_plane_x * sin(rot) + \
							player->plane_vector_y * cos(rot);
    player->angle += rot;
    if (player->angle > 2 * M_PI)
        player->angle -= 2 * M_PI;
    if (player->angle < 0)
        player->angle += 2 * M_PI;
}