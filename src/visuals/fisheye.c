/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fisheye.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:48:10 by tmalidi           #+#    #+#             */
/*   Updated: 2024/04/22 16:42:03 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	anti_fisheye(t_ray_data *ray, t_data *gd)
{
	double	ray_projection;
	double	angle;

	if (ray->id > (WINDOW_WIDTH - 1) / 2)
		angle = gd->angle * ((WINDOW_WIDTH / 2 - ray->id));
	else
		angle = gd->angle * (((WINDOW_WIDTH - ray->id) - (WINDOW_WIDTH / 2)));
	ray_projection = 0.5f * tan(angle) / tan(gd->copy_angle);
	return (roundf(WINDOW_WIDTH * (0.5f - ray_projection)));
}

void	draw_tex_process(t_data *game_data, int height, t_ray_data *ray)
{
	int	i;

	i = 0;
	while (i < height)
	{
		draw_tex(game_data, ray, i, height);
		if (game_data->len == 1)
		{
			game_data->c++;
			draw_tex(game_data, ray, i, height);
			game_data->c--;
		}
		i++;
	}
}

void init_tex_img(t_data *param)
{
	(void)param;
	// int	i;

	// i = 0;
	// while (i < TEX_SIDE)
	// 	param->tex_west.img[i] = NULL;
	// i = 0;
	// while (i < TEX_SIDE)
	// 	param->tex_east.img[i] = NULL;
	// i = 0;
	// while (i < TEX_SIDE)
	// 	param->tex_north.img[i] = NULL;
	// i = 0;
	// while (i < TEX_SIDE)
	// 	param->tex_south.img[i] = NULL;
}