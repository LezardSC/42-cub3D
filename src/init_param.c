/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:09:29 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/19 15:56:00 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	init_param(t_data *param)
{
	int	i;

	(void)param;
	i = 3;
	param->floor_color = malloc(sizeof(int) * 3);
	while (--i >= 0)
		param->floor_color[i] = 0;
	i = 3;
	param->sky_color = malloc(sizeof(int) * 3);
	while (--i >= 0)
		param->sky_color[i] = 0;
	param->textures = malloc(sizeof(int) * 6);
	i = 6;
	while (--i >= 0)
		param->textures[i] = 0;
	param->map_textures = malloc(sizeof(char *) * (4 + 1));
	i = 4;
	while (--i >= 0)
		param->map_textures[i] = NULL;
	param->check_colors = malloc(sizeof(int) * 2);
	param->check_colors[F] = 0;
	param->check_colors[C] = 0;
	param->map = NULL;
	return (0);
}
