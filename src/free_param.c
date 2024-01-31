/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:53:14 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/31 10:49:52 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	free_double_array(t_data *param)
{
	int	i;

	i = 0;
	if (param->map)
	{
		while (param->map && param->map[i])
		{
			free(param->map[i]);
			i++;
		}
		free(param->map);
	}
}

int	free_all_param(t_data *param)
{
	int	i;

	free_double_array(param);
	free(param->map_name);
	free(param->textures);
	free(param->floor_color);
	free(param->sky_color);
	free(param->check_colors);
	i = 4;
	while (--i >= 0)
		free(param->map_textures[i]);
	free(param->map_textures);
	return (0);
}
