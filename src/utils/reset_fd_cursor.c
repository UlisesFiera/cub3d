/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_fd_cursor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:21:02 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/23 16:28:19 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reset_fd_cursor(t_cub3d_data *data)
{
	close(data->map_data->file_fd);
	data->map_data->file_fd = open(data->map_data->file, O_RDONLY);
	if (data->map_data->file_fd == -1)
		exitperror(data, ERR_OPEN);
}
