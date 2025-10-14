/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:34:44 by ulfernan          #+#    #+#             */
/*   Updated: 2025/10/14 18:56:08 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define DEFAULT "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"

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

# define SET_RGB 0
# define SET_COL 1
# define RESET_RGB 2

# define WIDTH 1280
# define HEIGHT 800

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

# define LEFT 65361
# define RIGHT 65363

# define M_PI 3.14159265358979323846
# define INFINITY 10000000000

# define NAME "ulfernan and asalguer's cub3D"

# include "libft.h"
# include "mlx.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>
# include <math.h>

typedef struct s_element
{
	int				type;
	char			*name;
	char			*path;
	int				found;
}					t_element;

typedef struct s_file_data
{
	char			*file;
	char			**processed_file;
	char			**map;
	t_element		**elements;
	int				total_elem;
	int				elem_found;
	int				file_fd;
	int				file_bread;
	int				map_height;
	int				map_width;
	int				fill_map_height;
	int				fill_map_width;
}					t_file_data;

typedef struct s_texture
{
	void			*img;
	char			*bytes;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_texture;

typedef struct s_graphics
{
	int				x_size;
	int				y_size;
	char			*n_texture;
	char			*s_texture;
	char			*w_texture;
	char			*e_texture;
	int				f_color;
	int				c_color;
	t_texture		*nwall_texture;
	t_texture		*swall_texture;
	t_texture		*wwall_texture;
	t_texture		*ewall_texture;
}					t_graphics;

typedef struct s_dda
{
	double			ray_dir_x;
	double			ray_dir_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	int				step_x;
	int				step_y;
	double			perp_wall_dist;
	int				draw_start;
	int				draw_end;
	t_texture		*wall_texture;
	int				wall_color;
	int				side;
	double			slice_height;
	double			sampling;
	double			tex_pos;
	int				tex_y;
	int				tex_x;
}					t_dda;

typedef struct s_cub3d_data	t_cub3d_data;

typedef struct s_player
{
	bool			key_up;
	bool			key_left;
	bool			key_down;
	bool			key_right;
	bool			rotate_left;
	bool			rotate_right;
	double			angle;
	double			x;
	double			y;
	double			plane_vector_x;
	double			plane_vector_y;
	int				map_x;
	int				map_y;
	double			move_speed;
	double			rot_speed;
	double			dir_x;
	double			dir_y;
	t_cub3d_data	*data;
}					t_player;

typedef struct s_cub3d_data
{
	void			*mlx_id;
	void			*win;
	void			*img;
	char			*metadata;
	int				bpp;
	int				size_line;
	int				endian;
	int				win_height;
	int				win_width;
	t_file_data		*file_data;
	t_graphics		*graph_data;
	t_player		*player;
	t_dda			*dda;
}					t_cub3d_data;

/* main functions */
void	free_data(t_cub3d_data *data);
void	free_file_data(t_file_data *file);
void	*smalloc(size_t bytes);
void	init_data(char **argv, t_cub3d_data *data);

/* window */
int		close_window(t_cub3d_data *data);
void	window_manage(t_cub3d_data *data);

/* controls */
void	triggers(t_cub3d_data *data);

/* map parse */
void	parse_file(t_cub3d_data *data, char **argv);
void	map_size(t_cub3d_data *data);
void	validate_file(t_cub3d_data *data);
void	init_map(t_cub3d_data *data, char **argv);
void	parse_elements(t_cub3d_data *data);
void	parse_map(t_cub3d_data *data, int index);
void	check_walls(t_cub3d_data *data);

/* player */
void	init_player(t_cub3d_data *data);
int		key_press(int keycode, void *param);
int		key_release(int keycode, void *param);
void	rotate_player(t_player *player);
void	update_player(t_cub3d_data *data);
void	get_dir(t_player *player);

/* error */
void	invalid_char(char chr, t_cub3d_data *data);
void	dup_element(char *elem, t_cub3d_data *data);
void	openmaperr(char **map, int row, int col);
void	exitperror(t_cub3d_data *data, int errcode);
void	exiterr(char *error_text, t_cub3d_data *data, int errcode);
void	bad_color(t_cub3d_data *data, char *number);
void	dup_dir_element(t_cub3d_data *data);
void	no_dir_found(t_cub3d_data *data);

/* graphic */
void	init_graphic(t_cub3d_data *data);
int		parse_color(t_cub3d_data *data, char *color);
int		render_loop(t_cub3d_data *data);
void	put_pixel(t_cub3d_data *data, int x, int y, int color);
void	draw_slice(t_cub3d_data *data, int x);
void	draw_background(t_cub3d_data *data);
void	load_textures(t_cub3d_data *data);
void	assign_texture_to_sides(t_cub3d_data *data, int *side);
int		get_tex_x(t_cub3d_data *data);

/* dda */
void	ray_normalization(t_cub3d_data *data, int x);
void	set_player_cell(t_cub3d_data *data);
void	set_ray_units_size(t_cub3d_data *data);
void	setup_ray_dir_and_start_pos(t_cub3d_data *data);
void	trace_ray(t_cub3d_data *data, int *side);
void	fix_wall_dist_and_fish_eye(t_cub3d_data *data, int *side);
void	col_setup(t_cub3d_data *data);

/* utils */
void	reset_fd_cursor(t_cub3d_data *data);
char	last_char(char *string);
char	tab_reader(char **tab, int reset);
void	rm_tabs(t_cub3d_data *data, int row);
int		is_wall(t_cub3d_data *data, double x, double y);

#endif

/*

Error codes:

	- 00X generic errors
	- 10X system errors
	- 20X mlx errors
	- 30X map errors
	- 40x graphic errors
	
*/