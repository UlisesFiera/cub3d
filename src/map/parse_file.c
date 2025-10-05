/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:07:08 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/24 10:53:10 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	char **alloc_file(t_cub3d_data *data)
{
	char	**pfile;
	char	*reader;
	int		count;
	int		i;

	count = 0;
	while (1)
	{
		reader = get_next_line(data->file_data->file_fd);
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
	i = 0;
	while (i < count)
		pfile[i++] = NULL;
	pfile[count] = NULL;
	return (pfile);
}

static	void process_file(t_cub3d_data *data)
{
	char	*line;
	int		i;

	data->file_data->processed_file = alloc_file(data);
	reset_fd_cursor(data);
	i = 0;
	while (1)
	{
		line = get_next_line(data->file_data->file_fd);
		if (line)
		{
			data->file_data->processed_file[i] = ft_strdup(line);
			if (!data->file_data->processed_file[i])
				exiterr("fatal: malloc error in strdup", data, 101);
			free(line);
			i++;
		}
		else
			break ;
	}
}

static	void check_extension(t_cub3d_data *data)
{
	int	i;

	i = 0;
	while (data->file_data->file[i])
		i++;
	while (data->file_data->file[i] != '.')
		i--;
	if (i == 0)
		exiterr("only .cub files accepted as arg", data, 301);
	if (ft_strncmp(".cub", data->file_data->file + i,
			ft_strlen(data->file_data->file + 1)))
		exiterr("only .cub files accepted as arg", data, 301);
}

void	parse_file(t_cub3d_data *data, char **argv)
{
	data->file_data->file = argv[1];
	check_extension(data);
	data->file_data->file_fd = open(data->file_data->file, O_RDONLY);
	if (data->file_data->file_fd == -1)
		exitperror(data, ERR_OPEN);
	process_file(data);
	parse_elements(data);
	validate_file(data);
}
