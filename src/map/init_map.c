/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:19:06 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/23 16:27:06 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_element	*init_element(char *name, int type)
{
	t_element *element;

	element = smalloc(sizeof(t_element));
	element->type = type;
	element->name = name;
	element->path = NULL;
	element->found = 0;
	return (element);
}

void	init_element_list(t_cub3d_data *data)
{	
	data->map_data->elements[0] = init_element("NO ", ELEM_ORIENT);
	data->map_data->elements[1] = init_element("SO ", ELEM_ORIENT);
	data->map_data->elements[2] = init_element("WE ", ELEM_ORIENT);
	data->map_data->elements[3] = init_element("EA ", ELEM_ORIENT);
	data->map_data->elements[4] = init_element("F ", ELEM_OTHER);
	data->map_data->elements[5] = init_element("C ", ELEM_OTHER);
}

void	init_map(t_cub3d_data *data, char **argv)
{
	data->map_data->processed_file = NULL;
	data->map_data->map = NULL;
	data->map_data->file = NULL;
	data->map_data->file_fd = INULL;
	data->map_data->map_height = 0;
	data->map_data->map_width = 0;
	data->map_data->file_bread = 0;
	data->map_data->total_elem = 6;
	data->map_data->elements = smalloc(
		sizeof(t_element *) * (data->map_data->total_elem + 1));
	data->map_data->elements[data->map_data->total_elem] = NULL;
	init_element_list(data);
	data->map_data->elem_found = 0;
	parse_file(data, argv);
}
