/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:52:40 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/25 18:45:26 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	reset_rgb(int *r, int *g, int *b)
{
	*r = -1;
	*g = -1;
	*b = -1;
	return (0);
}

int	set_rgb(char *number, int *r, int *g, int *b)
{
	if (*r == -1)
	{
		*r = ft_atoi(number);
		if (*r > 255 || *r < 0)
			return (-1);
	}
	else if (*g == -1)
	{
		*g = ft_atoi(number);
		if (*g > 255 || *g < 0)
			return (-1);
	}
	else if (*b == -1)
	{
		*b = ft_atoi(number);
		if (*b > 255 || *b < 0)
			return (-1);
	}
	return (0);
}

int	set_color(char *number, int opcode, t_cub3d_data *data)
{
	static int	r = -1;
	static int	g = -1;
	static int	b = -1;
	int			color;

	if (opcode == SET_RGB)
	{
		if (set_rgb(number, &r, &g, &b) == -1)
			bad_color(data, number);
		return (0);
	}
	else if (opcode == SET_COL)
	{
		if (r == -1 || g == -1 || b == -1)
			bad_color(data, number);
		color = (r << 16) | (g << 8) | b;
		return (color);
	}
	else
		return (reset_rgb(&r, &g, &b));
}

char	*alloc_number(void)
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

int	parse_color(t_cub3d_data *data, char *color)
{
	char	*number;
	int		i;
	int		j;

	i = 0;
	set_color(NULL, RESET_RGB, data);
	while (color[i])
	{
		while (color[i] == ' ' || color[i] == ',')
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
