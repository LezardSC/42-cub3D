/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:06:01 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/26 03:15:19 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	all_infos_here(t_data *param)
{
	int	check;

	check = 0;
	if (param->textures[NO])
		check++;
	if (param->textures[SO])
		check++;
	if (param->textures[WE])
		check++;
	if (param->textures[EA])
		check++;
	if (param->check_colors[F])
		check++;
	if (param->check_colors[C])
		check++;
	if (check == 6)
		return (1);
	return (0);
}

int	find_infos(t_data *param)
{
	char	*buf;
	int		size;

	size = 0;
	buf = get_next_line(param->fd);
	if (!buf)
		return (ft_printf("Error\nget_next_line error\n"), 1);
	while (!is_line_map(buf))
	{
		param->nb_lines++;
		if (fill_textures_colors(buf, param) == 1)
			return (free(buf), 1);
		free(buf);
		buf = get_next_line(param->fd);
	}
	param->beginning_map = param->nb_lines + 1;
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
	free(buf);
	if (!all_infos_here(param))
		return (ft_printf("Error\nMissing infos\n"), 1);
	return (0);
}
