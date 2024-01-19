/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:09:51 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/19 17:16:15 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	fill_texture(char *buf, t_data *param, int which)
{
	int	i;
	int	j;
	int	size;

	i = 2;
	if (param->textures[which])
		return (1);
	while (buf[i] == ' ')
		i++;
	size = ft_strlen_space(&(buf[i]));
	param->map_textures[which] = malloc(sizeof(char *) * (size + 1));
	if (!param->map_textures[which])
		return (1);
	j = 0;
	while (buf[i] && buf[i] != ' ' && buf[i] != '\n')
	{
		param->map_textures[which][j] = buf[i];
		i++;
		j++;
	}
	param->map_textures[which][j] = '\0';
	param->textures[which] += 1;
	return (0);
}

static int	fill_color(char *buf, int *array_color, int i, int already_filled)
{
	int	count;
	int	nb;

	count = 0;
	nb = 0;
	if (already_filled)
		return (1);
	while (buf[++i] && count < 3)
	{
		if (nb > 255 || nb < 0)
			return (1);
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
	}
	if (count < 3)
		array_color[count] = nb;
	return (0);
}

static int	check_to_fill_textures(char *buf, t_data *param)
{
	if (buf[0] == 'N' && buf[1] == 'O')
	{
		if (fill_texture(buf, param, NO) == 1)
			return (ft_printf("Error\nTexture invalid\n"), 1);
	}
	else if (buf[0] == 'S' && buf[1] == 'O')
	{
		if (fill_texture(buf, param, SO) == 1)
			return (ft_printf("Error\nTexture invalid\n"), 1);
	}
	else if (buf[0] == 'W' && buf[1] == 'E')
	{
		if (fill_texture(buf, param, WE) == 1)
			return (ft_printf("Error\nTexture invalid\n"), 1);
	}
	else if (buf[0] == 'E' && buf[1] == 'A')
	{
		if (fill_texture(buf, param, EA) == 1)
			return (ft_printf("Error\nTexture invalid\n"), 1);
	}
	return (0);
}

int	fill_textures_colors(char *buf, t_data *param)
{
	if ((buf[0] == 'N' && buf[1] == 'O') || (buf[0] == 'S' && buf[1] == 'O')
		|| (buf[0] == 'W' && buf[1] == 'E') || (buf[0] == 'E' && buf[1] == 'A'))
	{
		if (check_to_fill_textures(buf, param) == 1)
			return (1);
	}
	else if (buf[0] == 'F')
	{
		if (fill_color(buf, param->floor_color, 0, param->check_colors[F]) == 1)
			return (ft_printf("Error\nFloor color invalid\n"), 1);
		else
			param->check_colors[F] += 1;
	}
	else if (buf[0] == 'C')
	{
		if (fill_color(buf, param->sky_color, 0, param->check_colors[C]) == 1)
			return (ft_printf("Error\nSky color invalid\n"), 1);
		else
			param->check_colors[C] += 1;
	}
	else
		if (is_space_or_newline(buf))
			return (ft_printf("Error\nThere is a wrong parameter\n"), 1);
	return (0);
}
