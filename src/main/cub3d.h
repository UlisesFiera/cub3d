/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:34:44 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/17 20:06:53 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# define RED_DOT "\033[31m●\033[0m\n"
# define GREEN_DOT "\033[32m●\033[0m\n"
# define YELLOW_DOT "\033[33m●\033[0m\n"

# include "../../libft/libft.h"
# include "../../minilibx/minilibx-linux/mlx.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <math.h>

typedef struct s_mlx_data
{
	void		*id;
	void		*win;
	t_map_data	*map;
	t_graphics	*graph;
}				t_mlx_data;

typedef struct s_map_data
{
	char		**map;
	void		*map_height;
	void		*map_width;
}				t_map_data;

typedef struct s_graphics
{
	void		*x_size;
	void		*y_size;
}				t_graphics;

// main functions

void	exiterr(char *error_text, t_mlx_data *mlx, int errcode);
void	free_mlx(t_mlx_data *mlx);
void	*smalloc(size_t bytes);

// window

void	window_manage(t_mlx_data *mlx);

#endif
