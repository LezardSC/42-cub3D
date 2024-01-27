/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:09:29 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/27 03:10:09 by jrenault         ###   ########lyon.fr   */
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

int	init_pixels(t_pixel *pixel)
{
	pixel->width = 16;
	pixel->height = 16;
	pixel->radius = 8;
	return (0);
}