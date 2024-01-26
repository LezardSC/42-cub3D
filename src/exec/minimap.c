/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:40:59 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/26 22:43:46 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	show_minimap(t_data *param)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (param->map[y])
	{
		while (param->map[y][x])
		{
			if (param->map[y][x] == '1')
			{
				my_mxl_pixel_put();
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
