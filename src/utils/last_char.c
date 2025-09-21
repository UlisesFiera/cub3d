/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:32:45 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/20 18:38:44 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	last_char(char *string)
{
	int	i;

	i = 0;
	if (!string || !string[i])
		return ('\0');
	while (string[i])
		i++;
	if (string[i] == '\0')
		i--;
	return (string[i]);
}
