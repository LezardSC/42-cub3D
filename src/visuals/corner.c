/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:38:09 by tmalidi           #+#    #+#             */
/*   Updated: 2024/04/19 16:42:48 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	other_corer(t_data *game_data, t_ray_data *ray, int i, float height)
{
	if (collision(game_data, ray->x, ray->y - 1)
		&& !collision(game_data, ray->x, ray->y + 1)
		&& !collision(game_data, ray->x + 1, ray->y)
		&& collision(game_data, ray->x - 1, ray->y))
	{
		if (game_data->pos_y < ray->y && game_data->pos_x > ray->x)
			return (get_pixel_color(game_data, i / height
					* WINDOW_HEIGHT, (TEX_SIDE - 1) - (ray->x % TEX_SIDE), SO));
		else
			return (get_pixel_color(game_data, i / height
					* WINDOW_HEIGHT, ray->y % TEX_SIDE, EA));
	}
	else
	{
		if (game_data->pos_y > ray->y && game_data->pos_x > ray->x)
			return (get_pixel_color(game_data, i / height
					* WINDOW_HEIGHT, ray->x % TEX_SIDE, NO));
		else
			return (get_pixel_color(game_data, i / height
					* WINDOW_HEIGHT, ray->y % TEX_SIDE, EA));
	}
}

int	corner(t_data *game_data, t_ray_data *ray, int i, float height)
{
	if (!collision(game_data, ray->x, ray->y - 1)
		&& collision(game_data, ray->x, ray->y + 1)
		&& collision(game_data, ray->x + 1, ray->y)
		&& !collision(game_data, ray->x - 1, ray->y))
	{
		if (game_data->pos_x < ray->x)
			return (get_pixel_color(game_data, i / height
					* WINDOW_HEIGHT, ray->x % TEX_SIDE, NO));
		else
			return (get_pixel_color(game_data, i / height
					* WINDOW_HEIGHT, (TEX_SIDE - 1) - (ray->y % TEX_SIDE), WE));
	}
	else if (collision(game_data, ray->x, ray->y - 1)
		&& !collision(game_data, ray->x, ray->y + 1)
		&& collision(game_data, ray->x + 1, ray->y)
		&& !collision(game_data, ray->x - 1, ray->y))
	{
		if (game_data->pos_y < ray->y && game_data->pos_x < ray->x)
			return (get_pixel_color(game_data, i / height
					* WINDOW_HEIGHT, (TEX_SIDE - 1) - (ray->x % TEX_SIDE), SO));
		else
			return (get_pixel_color(game_data, i / height
					* WINDOW_HEIGHT, (TEX_SIDE - 1) - (ray->y % TEX_SIDE), WE));
	}
	return (other_corer(game_data, ray, i, height));
}
