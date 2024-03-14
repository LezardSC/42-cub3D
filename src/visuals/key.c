/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:54:28 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/14 16:24:06 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	front_back_move(int key, t_data *gd)
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
		gd->x2 = gd->x2 * cos(gd->angle) + gd->y2 * sin(gd->angle);
		gd->y2 = -gd->x2 * sin(gd->angle) + gd->y2 * cos(gd->angle);
	}
	else if (key == 65363)
	{
		gd->x2 = gd->x2 * cos(gd->angle) - gd->y2 * sin(gd->angle);
		gd->y2 = gd->x2 * sin(gd->angle) + gd->y2 * cos(gd->angle);
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
	if (key == 119 || key == 65362)
	{
		gd->pos_y += (gd->x2 * sin(gd->copy_angle)
				+ gd->y2 * cos(gd->copy_angle)) / 100;
		gd->pos_x += (gd->x2 * cos(gd->copy_angle)
				- gd->y2 * sin(gd->copy_angle)) / 100;
	}
	else if (key == 115 || key == 65364)
	{
		gd->pos_y -= (gd->x2 * sin(gd->copy_angle)
				+ gd->y2 * cos(gd->copy_angle)) / 100;
		gd->pos_x -= (gd->x2 * cos(gd->copy_angle)
				- gd->y2 * sin(gd->copy_angle)) / 100;
	}
	else if (key == ROTATE_LEFT2 || key == ROTATE_RIGHT2)
		rotate_view(key,gd);
	else if (key == ROTATE_RIGHT || key == ROTATE_LEFT)
		front_back_move(key, gd);
	if (!collision(gd,gd->pos_x,gd->pos_y))
	{
		gd->pos_x = tmp_x;
		gd->pos_y = tmp_y;
	}
	mlx_clear_window(gd->mlx,gd->win);
	draw_floor(gd);
	draw_player_view(gd);
	gd->player.pos_x = gd->pos_x * (gd->max_x * gd->pixel.size)/1920;
	gd->player.pos_y = gd->pos_y * (gd->max_y * gd->pixel.size)/1080;
	//printf("%f | %f\n", gd->player.pos_x, gd->player.pos_x);
	show_minimap(gd);
	mlx_put_image_to_window(gd->mlx,gd->win,gd->pixel.img,0,0);
	return (0);
}
