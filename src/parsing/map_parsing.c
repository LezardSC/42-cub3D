/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:47:26 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/19 18:38:53 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	is_line_map(char *buf)
{
	int	i;

	i = 1;
	if (buf[0] == '1' || buf[0] == '0' || (buf[0] == 'N' && buf[1] != 'O'))
		return (1);
	else if (buf[0] == ' ')
	{
		while (buf[i])
		{
			if (buf[i] == '1' || buf[i] == '0' || buf[i] == 'N')
				return (1);
			i++;
		}
	}
	return (0);
}

int	is_name_correct(t_data *param)
{
	int	size;

	size = ft_strlen(param->map_name);
	if (size >= 5 && param->map_name[size - 1] == 'b'
		&& param->map_name[size - 2] == 'u' && param->map_name[size - 3] == 'c'
		&& param->map_name[size - 4] == '.')
		return (0);
	ft_printf("Error\nThe map is not a valid \".cub\"");
	return (1);
}

static int	get_max_x_and_y(t_data *param)
{
	char	*buf;
	int		size;

	param->nb_lines = 0;
	size = 0;
	param->max_x = 0;
	param->fd = open(param->map_name, O_RDONLY);
	if (!param->fd)
		return (ft_printf("Error\nCouldn't open the file\n"), 1);
	buf = go_to_map(param);
	while (buf)
	{
		param->nb_lines++;
		size = ft_strlen(buf) - 1;
		if (size > param->max_x)
			param->max_x = size;
		free(buf);
		buf = get_next_line(param->fd);
	}
	free(buf);
	return (0);
}

static int	allocate_map(t_data *param)
{
	int		size;
	int		i;

	i = 0;
	size = param->max_y - param->min_y;
	param->map = malloc(sizeof(char *) * (size + 1));
	if (!param->map)
		return (1);
	while (i < size)
	{
		param->map[i] = malloc(sizeof(char) * (param->max_x + 1));
		if (!param->map[i])
			return (1);
		i++;
	}
	param->map[i] = NULL;
	return (0);
}

static int	fill_map(t_data *param)
{
	int		i;
	char	*buf;

	i = 0;
	(void)i;
	param->fd = open(param->map_name, O_RDONLY);
	if (param->fd == -1)
		return (ft_printf("Error\nCouldn't open the map.\n"), 1);
	buf = go_to_map(param);
	if (!buf)
		return (1);
	free(buf);
	return (0);
}

int	map_parsing(t_data *param)
{
	param->fd = open(param->map_name, O_RDONLY);
	if (param->fd == -1)
		return (ft_printf("Error\nCouldn't open the map.\n"), 1);
	param->nb_lines = 0;
	if (find_infos(param) == 1)
		return (1);
	param->min_y = param->nb_lines + 1;
	close(param->fd);
	if (get_max_x_and_y(param) == 1)
		return (1);
	param->max_y = param->nb_lines;
	if (allocate_map(param) == 1)
		return (1);
	close(param->fd);
	if (fill_map(param) == 1)
		return (1);
	return (0);
}
