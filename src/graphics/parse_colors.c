/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:52:40 by ulfernan          #+#    #+#             */
/*   Updated: 2025/10/13 11:47:56 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*alloc_number(void)
{
	char	*number;
	int		size;
	int		i;

	size = 3;
	number = smalloc(size + 1);
	number[size] = '\0';
	i = 0;
	while (i < size)
		number[i++] = '\0';
	return (number);
}

void	initial_check(t_cub3d_data *data, char *color, int *index)
{
	set_color(NULL, RESET_RGB, data);
	while (color[*index] == ' ')
		(*index)++;
	if (!(color[*index] >= '0' && color[*index] <= '9'))
		invalid_char(color[*index], data);
}

int	parse_color(t_cub3d_data *data, char *color)
{
	char	*number;
	int		i;
	int		j;

	i = 0;
	initial_check(data, color, &i);
	while (color[i])
	{
		if (color[i] == ',')
			i++;
		if (!(color[i] >= '0' && color[i] <= '9'))
			invalid_char(color[i], data);
		j = 0;
		if (color[i] >= '0' && color[i] <= '9')
		{
			number = alloc_number();
			while (color[i] >= '0' && color[i] <= '9')
				number[j++] = color[i++];
			set_color(number, SET_RGB, data);
			free(number);
		}
		else
			i++;
	}
	return (set_color(NULL, SET_COL, data));
}
