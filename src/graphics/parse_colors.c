/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:52:40 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/25 17:54:03 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_color(char *number, int opcode)
{
	static int	r = -1;
	static int	g = -1;
	static int	b = -1;
	int			color;

	if (opcode == 0)
	{
		if (r == -1)
			r = ft_atoi(number);
		else if (g == -1)
			g = ft_atoi(number);
		else if (b == -1)
			b = ft_atoi(number);
		return (0);
	}
	else if (opcode == 1)
	{
		color = (r << 16) | (g << 8) | b;
		return (color);
	}
	else if (opcode == 2)
	{
		r = -1;
		g = -1;
		b = -1;
		return (0);
	}
	return (0);
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

int	parse_color(char *color) // missing check for digits max 255 and not empty or negative
{
	char	*number;
	int		i;
	int		j;

	i = 0;
	set_color(NULL, 2);
	while (color[i])
	{
		while (color[i] == ' ' || color[i] == ',')
			i++;
		j = 0;
		if (color[i] >= '0' && color[i] <= '9')
		{
			number = alloc_number();
			while (color[i] >= '0' && color[i] <= '9')
				number[j++] = color[i++];
			printf("%s\n", number);
			set_color(number, 0);
			free(number);
		}
		else
			i++;
	}
	return (set_color(NULL, 1));
}
