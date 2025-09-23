/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:07:08 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/23 18:46:12 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**alloc_file(t_cub3d_data *data)
{
	char	**pfile;
	char	*reader;
	int		count;

	count = 0;
	while (1)
	{
		reader = get_next_line(data->map_data->file_fd);
		if (reader)
		{
			count++;
			free(reader);
		}
		else
			break ;
	}
	if (count == 0)
		exiterr("empty file", data, 301);
	pfile = smalloc(sizeof(char *) * (count + 1));
	pfile[count] = NULL;
	return (pfile);
}

void	process_file(t_cub3d_data *data)
{
	char	**pfile;
	int		i;

	pfile = alloc_file(data);
	reset_fd_cursor(data);
	i = 0;
	while (1)
	{
		pfile[i] = get_next_line(data->map_data->file_fd);
		if (pfile[i])
			i++;
		else
			break ;
	}
	data->map_data->processed_file = pfile;
	i = 0;
	while (pfile[i])
		free(pfile[i++]);
	free(pfile);
}

void	check_extension(t_cub3d_data *data)
{
	int	i;

	i = 0;
	while (data->map_data->file[i])
		i++;
	while (data->map_data->file[i] != '.')
		i--;
	if (i == 0)
		exiterr("only .cub files accepted as arg", data, 301);
	if (ft_strncmp(".cub", data->map_data->file + i, ft_strlen(data->map_data->file + 1)))
		exiterr("only .cub files accepted as arg", data, 301);
}

void	parse_file(t_cub3d_data *data, char **argv)
{
	data->map_data->file = argv[1];
	check_extension(data);
	data->map_data->file_fd = open(data->map_data->file, O_RDONLY);
	if (data->map_data->file_fd == -1)
		exitperror(data, ERR_OPEN);
	process_file(data);
	parse_elements(data);
	validate_file(data);
}
