/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:47:26 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/18 14:54:16 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	error_parsing(int num_error)
{
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

// static int	find_end_map(t_data *param, int fd)
// {
// 	char	*buf;
// 	int		n;

// 	n = 0;
// 	buf = get_next_line(fd);
// 	if (!buf)
// 		return (close(fd), -2);
// 	while (buf)
// 	{
// 		if (n == param->min_y)
// 			break ;
// 		n++;
// 		free(buf);
// 		buf = get_next_line(fd);
// 	}
// 	while (buf)
// 	{
// 		if (!is_line_map(buf))
// 			return (close(fd), free(buf), n);
// 		else
// 			n++;
// 		free(buf);
// 		buf = get_next_line(fd);
// 	}
// 	return (close(fd), n);
// }

// static int	find_beginning_map(t_data *param, int fd)
// {
// 	char	*buf;
// 	int		n;

// 	(void)param;
// 	n = 0;
// 	buf = get_next_line(fd);
// 	if (!buf)
// 		return (-1);
// 	while (buf)
// 	{
// 		n++;
// 		if (is_line_map(buf))
// 			return (free(buf), close(fd), n);
// 		free(buf);
// 		buf = get_next_line(fd);
// 	}
// 	return (close(fd), n);
// }

static int	find_infos(t_data *param, int fd)
{
	char	*buf;
	int		n;

	buf = get_next_line(fd);
	if (!buf)
		return (ft_printf("Error\nget_next_line error", 1));
	n = 0;
	while (!is_line_map(buf))
	{
		n++;
		if (fill_textures_colors(buf, param) == 1)
			return (free(buf), close(fd), 1);
		free(buf);
		buf = get_next_line(fd);
	}
	free(buf);
	return (close(fd), 0);
}

int	map_parsing(t_data *param)
{
	int	fd;

	fd = open(param->map_name, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nCouldn't open the map.\n"), 1);
	if (find_infos(param, fd) == 1)
		return (1);
	// param->min_y = find_beginning_map(param, fd);
	// if (param->min_y == -1)
	// 	return (1);
	// param->max_y = find_end_map(param, fd);
	// if (param->min_y == -1)
	// 	return (1);
	return (0);
}
