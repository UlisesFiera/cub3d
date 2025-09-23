/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:58:05 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/23 18:20:15 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	tab_reader(char **tab, int reset)
{
	char		reader;
	static int	row = 0;
	static int	column = 0;
	
	if (!tab || !tab[row])
		return ('\0');
	if (reset == 1)
	{
		row = 0;
		column = 0;
	}
	if (tab[row][column])
	{
		reader = tab[row][column];
		column++;
		return (reader);
	}
	else
	{
		column = 0;
		row++;
		if (!tab[row])
		{
			row = 0;
			column = 0;
			return ('\0');
		}
		reader = tab[row][column];
		return (reader);
	}
}
