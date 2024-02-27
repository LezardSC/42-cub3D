/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 02:38:40 by jrenault          #+#    #+#             */
/*   Updated: 2024/02/02 17:25:14 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

//	Fill the minimap with black. It was too difficult to update the map if there was no background.

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
			my_mlx_pixel_put_mini(&param->drawmm, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

//get the first position of the player in the parsing then delete it so the position is now stocked in the struct.

static void	player_first_position(t_data *param, int y, int x)
{
	param->map[y][x] = '0';
	param->player.pos_x = x * param->drawmm.size
		+ param->drawmm.radius;
	param->player.pos_y = y * param->drawmm.size
		+ param->drawmm.radius;
}

//display the minimap on the screen by creating a square each time it see a wall.
//the player will be drawn in the move_player functions.

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
				my_mlx_square_put(&param->drawmm, (x * param->drawmm.size),
					(y * param->drawmm.size), RED_COLOR);
			if (param->map[y][x] == 'N' || param->map[y][x] == 'E'
				|| param->map[y][x] == 'W' || param->map[y][x] == 'S')
				player_first_position(param, y, x);
			x++;
		}
		x = 0;
	}
	my_mlx_circle_put(param, BLUE_COLOR);
	mlx_put_image_to_window(param->mlx, param->win, param->drawmm.img, 0, 0);
	return (0);
}
