/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:43:07 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/22 14:03:18 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_tex_data(t_tex_data *data, t_data *game_data, int ray)
{
	data->bpp = 0;
	data->sl = 0;
	data->endian = 0;
	data->original_width = TEX_SIDE;
	data->original_height = TEX_SIDE;
	data->enlarged_wall = mlx_new_image
		(game_data->mlx, 1, 1080);
	data->enlarged_wall_data = mlx_get_data_addr
		(data->enlarged_wall, &data->bpp, &data->sl, &data->endian);
	data->original_x = ray % TEX_SIDE;
}

char	*new_display(t_data *game_data, char *wall_data, int ray)
{
	t_tex_data	data;
	int			y;
	int			i;

	y = 0;
	init_tex_data(&data, game_data, ray);
	while (y < 1080)
	{
		data.original_y = y * data.original_height / 1080;
		data.original_index = data.original_y * data.original_width
			* (data.bpp / 8) + data.original_x * (data.bpp / 8);
		data.enlarged_index = y * data.sl;
		i = 0;
		while (i < data.bpp / 8)
		{
			if (data.original_index + i < data.original_width
				* data.original_height * (data.bpp / 8)
				&& data.enlarged_index + i < 1 * 1080 * (data.bpp / 8))
				data.enlarged_wall_data[data.enlarged_index + i]
					= wall_data[data.original_index + i];
			i++;
		}
		y++;
	}
	return (data.enlarged_wall);
}
