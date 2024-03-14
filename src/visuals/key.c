/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:54:28 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/14 22:10:23 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	left_right_move(int key, t_data *gd)
{
	if (key == ROTATE_LEFT)
	{
		gd->pos_y -= (gd->x2 * sin(120 * M_PI / 180.0)
				+ gd->y2 * cos(120 * M_PI / 180.0)) / 100;
		gd->pos_x -= (gd->x2 * cos(120 * M_PI / 180.0)
				- gd->y2 * sin(120 * M_PI / 180.0)) / 100;
	}
	else if (key == ROTATE_RIGHT)
	{
		gd->pos_y += (gd->x2 * sin(120 * M_PI / 180.0)
				+ gd->y2 * cos(120 * M_PI / 180.0)) / 100;
		gd->pos_x += (gd->x2 * cos(120 * M_PI / 180.0)
				- gd->y2 * sin(120 * M_PI / 180.0)) / 100;
	}
}

void	rotate_view(int key, t_data *gd)
{
	if (key == 65361)
	{
		gd->x2 = gd->x2 * cos(ROTATION_SPEED) + gd->y2 * sin(ROTATION_SPEED);
		gd->y2 = -gd->x2 * sin(ROTATION_SPEED) + gd->y2 * cos(ROTATION_SPEED);
	}
	else if (key == 65363)
	{
		gd->x2 = gd->x2 * cos(ROTATION_SPEED) - gd->y2 * sin(ROTATION_SPEED);
		gd->y2 = gd->x2 * sin(ROTATION_SPEED) + gd->y2 * cos(ROTATION_SPEED);
	}
}

void	front_back_move(int key, t_data *gd)
{
	if (key == 119)
	{
		gd->pos_y += (gd->x2 * sin(gd->copy_angle)
				+ gd->y2 * cos(gd->copy_angle)) / 100;
		gd->pos_x += (gd->x2 * cos(gd->copy_angle)
				- gd->y2 * sin(gd->copy_angle)) / 100;
	}
	else if (key == 115)
	{
		gd->pos_y -= (gd->x2 * sin(gd->copy_angle)
				+ gd->y2 * cos(gd->copy_angle)) / 100;
		gd->pos_x -= (gd->x2 * cos(gd->copy_angle)
				- gd->y2 * sin(gd->copy_angle)) / 100;
	}
}

int	ft_key(int key, t_data *gd)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = gd->pos_x;
	tmp_y = gd->pos_y;
	if (key == 65307)
		exit_game(gd);
	else if (key == 119 || key == 115)
		front_back_move(key, gd);
	else if (key == ROTATE_LEFT2 || key == ROTATE_RIGHT2)
		rotate_view(key, gd);
	else if (key == ROTATE_RIGHT || key == ROTATE_LEFT)
		left_right_move(key, gd);
	if (!collision(gd, gd->pos_x, gd->pos_y))
	{
		gd->pos_x = tmp_x;
		gd->pos_y = tmp_y;
	}
	draw_floor(gd);
	draw_player_view(gd);
	gd->player.pos_x = gd->pos_x * (gd->max_x * gd->pixel.size) / 1920;
	gd->player.pos_y = gd->pos_y * (gd->max_y * gd->pixel.size) / 1080;
	show_minimap(gd);
	mlx_put_image_to_window(gd->mlx, gd->win, gd->pixel.img, 0, 0);
	return (0);
}
