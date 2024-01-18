/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:09:29 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/18 14:17:15 by jrenault         ###   ########lyon.fr   */
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
	param->map = NULL;
	param->map_textures = NULL;
	return (0);
}
