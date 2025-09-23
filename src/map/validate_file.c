/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:49:02 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/23 18:23:17 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_chars(t_cub3d_data *data)
{
	char	reader;
	
	while (1)
	{
		reader = tab_reader(data->map_data->map, 0);
		if (reader == '\0')
			break ;
		if (reader != '0' && reader != '1' && reader != 'N' && reader != 'S'
			&& reader != 'W' && reader != 'E' && reader != '\n' && reader != ' ')
			invalid_char(reader, data);
	}
}

void	validate_file(t_cub3d_data *data)
{
	check_chars(data);
}