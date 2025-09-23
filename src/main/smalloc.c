/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:26:48 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/21 14:37:41 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	*smalloc(size_t bytes)
{
	void	*memory;

	memory = malloc(bytes);
	if (memory == NULL)
		exiterr("malloc couldn't allocate enough memory", NULL, 101);
	return (memory);
}
