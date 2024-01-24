/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:47:26 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/20 15:30:57 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

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
		size = ft_strlen(buf);
		if (size > param->max_x)
			param->max_x = size;
		free(buf);
		buf = get_next_line(param->fd);
	}
	param->max_x -= 2;
	param->nb_lines--;
	free(buf);
	return (0);
}

static int	allocate_map(t_data *param)
{
	int		i;

	i = 0;
	param->map = malloc(sizeof(char *) * (param->max_y + 1));
	if (!param->map)
		return (1);
	while (i < param->max_y)
	{
		param->map[i] = malloc(sizeof(char) * (param->max_x + 1));
		if (!param->map[i])
			return (1);
		i++;
	}
	param->map[i] = NULL;
	return (0);
}

static int	fill_line_map(char *buf, t_data *param, int i)
{
	int	j;

	j = 0;
	if (!is_line_map(buf))
		return (1);
	// ft_printf("buf: %s\n", buf);
	while (buf[j] && buf[j] != '\n')
	{
		param->map[i][j] = buf[j];
		j++;
	}
	while (j <= param->max_x)
	{
		param->map[i][j] = ' ';
		j++;
	}
	param->map[i][j] = '\0';
	return (0);
}

static int	fill_map(t_data *param)
{
	int		i;
	char	*buf;

	i = 0;
	param->fd = open(param->map_name, O_RDONLY);
	if (param->fd == -1)
		return (ft_printf("Error\nCouldn't open the map.\n"), 1);
	buf = go_to_map(param);
	if (!buf)
		return (1);
	while (buf)
	{
		if (fill_line_map(buf, param, i) == 1)
			return (ft_printf("Error\nmap invalid\n"), free(buf), 1);
		free(buf);
		buf = get_next_line(param->fd);
		i++;
	}
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
	param->beginning_map = param->nb_lines + 1;
	close(param->fd);
	if (get_max_x_and_y(param) == 1)
		return (1);
	param->max_y = param->nb_lines - param->beginning_map;
	ft_printf("max x: %d\nmax y: %d\n", param->max_x, param->max_y);
	if (allocate_map(param) == 1)
		return (1);
	close(param->fd);
	if (fill_map(param) == 1)
		return (1);
	return (0);
}
