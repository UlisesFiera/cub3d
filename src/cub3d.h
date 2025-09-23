/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:34:44 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/23 16:13:40 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define RED_DOT "\033[31m●\033[0m"
# define GREEN_DOT "\033[32m●\033[0m"
# define YELLOW_DOT "\033[33m●\033[0m"

# define INULL -918273645

# define ERR_OPEN 1

# define ELEM_ORIENT 0
# define ELEM_OTHER 1

# include "libft.h"
# include "mlx.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <math.h>

typedef struct s_element
{
	int		type;
	char	*name;
	char	*path;
	int		found;
}			t_element;

typedef struct s_map_data
{
	char		*file;
	char		**processed_file;
	char		**map;
	t_element	**elements;
	int			total_elem;
	int			elem_found;
	int			file_fd;
	int			file_bread;
	int			map_height;
	int			map_width;
}				t_map_data;

typedef struct s_graphics
{
	int			x_size;
	int			y_size;
	char		*n_texture;
	char		*s_texture;
	char		*w_texture;
	char		*e_texture;
}				t_graphics;

typedef struct s_cub3d_data
{
	void		*mlx_id;
	void		*win;
	int			win_height;
	int			win_width;
	t_map_data	*map_data;
	t_graphics	*graph_data;
}				t_cub3d_data;

// main functions

void	free_mlx(t_cub3d_data *data);
void	*smalloc(size_t bytes);
void	init_data(t_cub3d_data *data);
void	invalid_char(char chr, t_cub3d_data *data);
void	dup_element(char *elem, t_cub3d_data *data);

// window

void	window_manage(t_cub3d_data *data);
int		close_window(t_cub3d_data *data);

// controls

void	triggers(t_cub3d_data *data);

// map parse

void	parse_file(t_cub3d_data *data, char **argv);
void	map_size(t_cub3d_data *data);
void	validate_file(t_cub3d_data *data);
void	init_map(t_cub3d_data *data, char **argv);
void	parse_elements(t_cub3d_data *data);
void	parse_map(t_cub3d_data *data, char *line);

// error

void	exitperror(t_cub3d_data *data, int errcode);
void	exiterr(char *error_text, t_cub3d_data *data, int errcode);

// graphic

void	init_graphic(t_cub3d_data *data);

// utils

void	reset_fd_cursor(t_cub3d_data *data);
char	last_char(char *string);
char	tab_reader(char **tab, int reset);

#endif

/*

Error codes:

	- 00X generic errors
	- 10X system errors
	- 20X mlx errors
	- 30X map errors

*/