/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:47:26 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/17 17:43:30 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	error_parsing(int num_error)
{
	if (num_error == 1)
		ft_printf("Error\nCouldn't open the map.\n");
	if (num_error == 2)
		ft_printf("Error\nThe map is not a valid '.cub'.\n");
	if (num_error == 3)
		ft_printf("Error\nThe map is empty.\n");
	if (num_error == 4)
		ft_printf("Error\nget_next_line error.\n");
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
	error_parsing(2);
	return (1);
}

static int	find_end_map(t_data *param)
{
	int		fd;
	char	*buf;
	int		n;

	n = 0;
	fd = open(param->map_name, O_RDONLY);
	if (fd == -1)
		return (error_parsing(1), -1);
	buf = get_next_line(fd);
	if (!buf)
		return (close(fd), -2);
	while (buf)
	{
		if (n == param->min_y)
			break ;
		n++;
		free(buf);
		buf = get_next_line(fd);
	}
	while (buf)
	{
		if (!is_line_map(buf))
			return (close(fd), free(buf), n);
		else
			n++;
		free(buf);
		buf = get_next_line(fd);
	}
	return (close(fd), n);
}

static int	find_beginning_map(t_data *param)
{
	int		fd;
	char	*buf;
	int		n;

	if (is_name_correct(param) == 1)
		return (-1);
	n = 0;
	fd = open(param->map_name, O_RDONLY);
	if (fd == -1)
	{
		error_parsing(1);
		return (-1);
	}
	buf = get_next_line(fd);
	if (!buf)
		return (-1);
	while (buf)
	{
		n++;
		if (is_line_map(buf))
			return (free(buf), close(fd), n);
		free(buf);
		buf = get_next_line(fd);
	}
	return (close(fd), n);
}

int	map_parsing(t_data *param)
{
	param->min_y = find_beginning_map(param);
	if (param->min_y == -1)
		return (1);
	param->max_y = find_end_map(param);
	if (param->max_y == -1)
		return (1);
	if (check_infos(param) == 1)
		return (1);
	// param->map = malloc(sizeof(char *) * (param->max_y - param->min_y) + 1);
	// if (!param->map)
	// 	return (1);
	// param->map_infos = malloc(sizeof(char *) * 6 + 1);
	// if (!param->map_infos)
	// 	return (1);
	// if (info_map_parsing(param, -1) == 1)
	// 	return (1);
	return (0);
}
