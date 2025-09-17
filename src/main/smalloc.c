/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:26:48 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/17 20:07:09 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	*smalloc(size_t bytes)
{
	void	*memory;

	memory = malloc(bytes);
	if (memory == NULL)
		exiterr("Fatal: malloc couldn't allocate enough memory", NULL, 101);
	return (memory);
}
