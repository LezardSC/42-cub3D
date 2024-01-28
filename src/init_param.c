/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:09:29 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/28 03:29:39 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	init_param(t_data *param)
{
	int	i;

	i = 3;
	param->floor_color = malloc(sizeof(int) * 3);
	if (!param->floor_color)
		return (1);
	while (--i >= 0)
		param->floor_color[i] = 0;
	i = 3;
	param->sky_color = malloc(sizeof(int) * 3);
	if (!param->sky_color)
		return (1);
	while (--i >= 0)
		param->sky_color[i] = 0;
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
	param->check_colors = malloc(sizeof(int) * 2);
	if (!param->check_colors)
		return (1);
	param->check_colors[F] = 0;
	param->check_colors[C] = 0;
	param->map = NULL;
	return (0);
}

int	init_player(t_data *param)
{
	param->player.pos_x = 0;
	param->player.pos_y = 0;
	param->player.forward = FALSE;
	param->player.left = FALSE;
	param->player.right = FALSE;
	param->player.backward = FALSE;
	return (0);
}

int	init_pixels(t_data *param)
{
	if (param->max_x > param->max_y)
		param->pixel.size = (MINIMAP_WIDTH / (param->max_x + 1));
	else
		param->pixel.size = (MINIMAP_HEIGHT / (param->max_y + 1));
	param->pixel.radius = param->pixel.size / 2;
	return (0);
}
