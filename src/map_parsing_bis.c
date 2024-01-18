/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:55:54 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/18 14:59:21 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	fill_texture(char *buf, t_data *param, char *texture, int which)
{
	int	i;

	i = 2;
	if (param->textures[which])
		return (1);
	while (buf[i])
	{
	}
	param->textures[NO] += 1;
	return (0);
}

static int	fill_color(char *buf, int *array_color)
{
	int	i;
	int	count;
	int	nb;

	i = 1;
	count = 0;
	nb = 0;
	while (buf[i] && count < 3)
	{
		if (ft_isdigit(buf[i]))
			nb = nb * 10 + (buf[i] - '0');
		else if (buf[i] == ',')
		{
			array_color[count] = nb;
			nb = 0;
			count++;
		}
		else if (buf[i] != ' ' && buf[i] != '\n')
			return (1);
		i++;
	}
	if (count < 3)
		array_color[count] = nb;
	return (0);
}

int	fill_textures_colors(char *buf, t_data *param)
{
	int	i;

	i = 0;
	if (buf[0] == 'N' && buf[1] == 'O')
		fill_texture(buf, param, param->map_textures[NO], NO);
	if (buf[0] == 'S' && buf[1] == 'O')
		param->textures[SO] += 1;
	if (buf[0] == 'W' && buf[1] == 'E')
		param->textures[WE] += 1;
	if (buf[0] == 'E' && buf[1] == 'A')
		param->textures[EA] += 1;
	if (buf[0] == 'F')
	{
		if (fill_color(buf, param->floor_color) == 1)
			return (ft_printf("Error\nFloor color invalid\n"), 1);
	}
	if (buf[0] == 'C')
	{
		if (fill_color(buf, param->sky_color) == 1)
			return (ft_printf("Error\nSky color invalid\n"), 1);
	}
	return (0);
}

int	is_line_map(char *buf)
{
	int	i;

	i = 0;
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

// static int	find_max_x(t_data *param)
// {
// 	(void)param;
// 	return (0);
// }

// void	deal_with_empty_lines(t_data *param, int fd, int i)
// {
// 	while (param->map_infos[i][0] == '\n')
// 	{
// 		free(param->map_infos[i]);
// 		param->map_infos[i] = get_next_line(fd);
// 	}
// }
