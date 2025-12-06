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
