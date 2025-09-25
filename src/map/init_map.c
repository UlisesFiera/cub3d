/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:19:06 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/25 13:50:51 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_element	*init_element(char *name, int type)
{
	t_element	*element;

	element = smalloc(sizeof(t_element));
	element->type = type;
	element->name = name;
	element->path = NULL;
	element->found = 0;
	return (element);
}

void	init_element_list(t_cub3d_data *data)
{
	data->file_data->elements[0] = init_element("NO ", ELEM_NO);
	data->file_data->elements[1] = init_element("SO ", ELEM_SO);
	data->file_data->elements[2] = init_element("WE ", ELEM_WE);
	data->file_data->elements[3] = init_element("EA ", ELEM_EA);
	data->file_data->elements[4] = init_element("F ", ELEM_F);
	data->file_data->elements[5] = init_element("C ", ELEM_C);
}

void	init_map(t_cub3d_data *data, char **argv)
{
	data->file_data->processed_file = NULL;
	data->file_data->map = NULL;
	data->file_data->file = NULL;
	data->file_data->file_fd = INULL;
	data->file_data->map_height = 0;
	data->file_data->map_width = 0;
	data->file_data->fill_map_height = 0;
	data->file_data->fill_map_width = 0;
	data->file_data->file_bread = 0;
	data->file_data->total_elem = 6;
	data->file_data->elements = smalloc(
			sizeof(t_element *) * (data->file_data->total_elem + 1));
	data->file_data->elements[data->file_data->total_elem] = NULL;
	init_element_list(data);
	data->file_data->elem_found = 0;
	parse_file(data, argv);
}
