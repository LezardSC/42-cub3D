/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 02:38:40 by jrenault          #+#    #+#             */
/*   Updated: 2024/03/21 10:13:06 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	fill_minimap(t_data *param, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < MINIMAP_HEIGHT)
	{
		while (x < MINIMAP_WIDTH)
		{
			my_mlx_pixel_put(&param->pixel, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

static void	player_first_position(t_data *param, int y, int x)
{
	param->map[y][x] = '0';
	param->player.pos_x = x * param->pixel.size
		+ param->pixel.radius;
	param->player.pos_y = y * param->pixel.size
		+ param->pixel.radius;
	param->pos_x = param->player.pos_x * 1920
		/ (param->max_x * param->pixel.size);
	param->pos_y = param->player.pos_y * 1080
		/ (param->max_y * param->pixel.size);
}

int	show_minimap(t_data *param)
{
	int		x;
	int		y;

	x = 0;
	y = -1;
	fill_minimap(param, BLACK_COLOR);
	while (param->map[++y])
	{
		while (param->map[y][x])
		{
			if (param->map[y][x] == '1')
				my_mlx_square_put(&param->pixel, (x * param->pixel.size),
					(y * param->pixel.size), RED_COLOR);
			if (param->map[y][x] == 'N' || param->map[y][x] == 'E'
				|| param->map[y][x] == 'W' || param->map[y][x] == 'S')
				player_first_position(param, y, x);
			x++;
		}
		x = 0;
	}
	my_mlx_circle_put(param, BLUE_COLOR);
	mlx_put_image_to_window(param->mlx, param->win, param->pixel.img, 0, 0);
	return (0);
}
