/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:09:29 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/31 17:11:30 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	init_map(t_data *param, int i)
{
	param->floor_color = malloc(sizeof(int) * 3);
	if (!param->floor_color)
		return (1);
	param->sky_color = malloc(sizeof(int) * 3);
	if (!param->sky_color)
		return (1);
	i = 3;
	while (--i >= 0)
	{	
		param->floor_color[i] = 0;
		param->sky_color[i] = 0;
	}
	param->textures = malloc(sizeof(int) * 6);
	if (!param->textures)
		return (1);
	i = 6;
	while (--i >= 0)
		param->textures[i] = 0;
	param->map_textures = malloc(sizeof(char *) * (4 + 1));
	if (!param->map_textures)
		return (1);
	i = 4;
	while (--i >= 0)
		param->map_textures[i] = NULL;
	return (0);
}

static void	init_player(t_data *param)
{
	param->player.pos_x = 0;
	param->player.pos_y = 0;
	param->player.forward = FALSE;
	param->player.backward = FALSE;
	param->player.rotate_left = FALSE;
	param->player.rotate_right = FALSE;
	if (param->direction == 'N')
		param->player.angle = 90 * M_PI / 180.0;
	else if (param->direction == 'S')
		param->player.angle = 270 * M_PI / 180.0;
	else if (param->direction == 'E')
		param->player.angle = 0 * M_PI / 180.0;
	else if (param->direction == 'W')
		param->player.angle = 180 * M_PI / 180.0;
}

int	init_pixels(t_data *param)
{
	if (param->max_x > param->max_y)
		param->pixel.size = (MINIMAP_WIDTH / (param->max_x + 1));
	else
		param->pixel.size = (MINIMAP_HEIGHT / (param->max_y + 1));
	param->pixel.radius = param->pixel.size / 2;
	init_player(param);
	return (0);
}

int	init_param(t_data *param)
{
	if (init_map(param, 3) == 1)
		return (1);
	param->check_colors = malloc(sizeof(int) * 2);
	if (!param->check_colors)
		return (1);
	param->check_colors[F] = 0;
	param->check_colors[C] = 0;
	param->map = NULL;
	return (0);
}
