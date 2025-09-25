/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:34:44 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/25 17:53:36 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define RED_DOT "\033[31m●\033[0m"
# define GREEN_DOT "\033[32m●\033[0m"
# define YELLOW_DOT "\033[33m●\033[0m"

# define INULL -918273645

# define ERR_OPEN 1

# define ELEM_NO 0
# define ELEM_SO 1
# define ELEM_WE 2
# define ELEM_EA 3
# define ELEM_F 4
# define ELEM_C 5

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

typedef struct s_file_data
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
	int			fill_map_height;
	int			fill_map_width;
}				t_file_data;

typedef struct s_graphics
{
	int			x_size;
	int			y_size;
	char		*n_texture;
	char		*s_texture;
	char		*w_texture;
	char		*e_texture;
	int			f_color;
	int			c_color;
}				t_graphics;

typedef struct s_cub3d_data
{
	void		*mlx_id;
	void		*win;
	int			win_height;
	int			win_width;
	t_file_data	*file_data;
	t_graphics	*graph_data;
}				t_cub3d_data;

// main functions

void	free_data(t_cub3d_data *data);
void	free_file_data(t_file_data *file);
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
void	parse_map(t_cub3d_data *data, int index);
void	check_walls(t_cub3d_data *data);

// error

void	exitperror(t_cub3d_data *data, int errcode);
void	exiterr(char *error_text, t_cub3d_data *data, int errcode);
void	openmaperr(char **map, int row, int col);

// graphic

void	init_graphic(t_cub3d_data *data);
int		parse_color(char *color);

// utils

void	reset_fd_cursor(t_cub3d_data *data);
char	last_char(char *string);
char	tab_reader(char **tab, int reset);
void	rm_tabs(t_cub3d_data *data, int row);

#endif

/*

Error codes:

	- 00X generic errors
	- 10X system errors
	- 20X mlx errors
	- 30X map errors

*/