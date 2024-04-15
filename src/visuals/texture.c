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

static void	init_tex_data(t_tex_data *data, t_data *gd, int ray)
{
	data->bpp = 0;
	data->sl = 0;
	data->endian = 0;
	data->original_width = TEX_SIDE;
	data->original_height = TEX_SIDE;
	data->enlarged_wall = mlx_new_image
		(gd->mlx, 1, 1080);
	data->enlarged_wall_data = mlx_get_data_addr
		(data->enlarged_wall, &data->bpp, &data->sl, &data->endian);
	data->original_x = ray % TEX_SIDE;
}

char	*new_display(t_data *gd, char *wall_data, int ray)
{
	int			y;
	int			i;

	y = 0;
	init_tex_data(&gd->tdata, gd, ray);
	while (y < 1080)
	{
		gd->tdata.original_y = y * gd->tdata.original_height / 1080;
		gd->tdata.original_index = gd->tdata.original_y * gd->tdata.original_width
			* (gd->tdata.bpp / 8) + gd->tdata.original_x * (gd->tdata.bpp / 8);
		gd->tdata.enlarged_index = y * gd->tdata.sl;
		i = 0;
		while (i < gd->tdata.bpp / 8)
		{
			if (gd->tdata.original_index + i < gd->tdata.original_width
				* gd->tdata.original_height * (gd->tdata.bpp / 8)
				&& gd->tdata.enlarged_index + i < 1 * 1080 * (gd->tdata.bpp / 8))
				gd->tdata.enlarged_wall_data[gd->tdata.enlarged_index + i]
					= wall_data[gd->tdata.original_index + i];
			i++;
		}
		y++;
	}
	return (gd->tdata.enlarged_wall);
}
