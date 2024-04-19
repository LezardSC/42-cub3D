/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:54:28 by tmalidi           #+#    #+#             */
/*   Updated: 2024/04/19 16:29:53 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	left_right_move(int key, t_data *gd)
{
	if (key == ROTATE_LEFT)
	{
		gd->pos_y -= (gd->x2 * sin(gd->copy_angle + 90 * M_PI / 180)
				+ gd->y2 * cos(gd->copy_angle + 90 * M_PI / 180))
			/ (RAY_DISTANCE / 2) * 5;
		gd->pos_x -= (gd->x2 * cos(gd->copy_angle + 90 * M_PI / 180)
				- gd->y2 * sin(gd->copy_angle + 90 * M_PI / 180))
			/ (RAY_DISTANCE / 2) * 5;
	}
	else if (key == ROTATE_RIGHT)
	{
		gd->pos_y += (gd->x2 * sin(gd->copy_angle + 90 * M_PI / 180)
				+ gd->y2 * cos(gd->copy_angle + 90 * M_PI / 180))
			/ (RAY_DISTANCE / 2) * 5;
		gd->pos_x += (gd->x2 * cos(gd->copy_angle + 90 * M_PI / 180)
				- gd->y2 * sin(gd->copy_angle + 90 * M_PI / 180))
			/ (RAY_DISTANCE / 2) * 5;
	}
}

void	rotate_view(int key, t_data *gd)
{
	int	tmp;

	tmp = gd->x2;
	if (key == 65361)
	{
		gd->x2 = gd->x2 * cos(gd->copy_angle * (35 * M_PI / 180.0) / 5)
			+ gd->y2 * sin(gd->copy_angle * (35 * M_PI / 180.0) / 5);
		gd->y2 = -tmp * sin(gd->copy_angle * (35 * M_PI / 180.0) / 5)
			+ gd->y2 * cos(gd->copy_angle * (35 * M_PI / 180.0) / 5);
	}
	else if (key == 65363)
	{
		gd->x2 = gd->x2 * cos(gd->copy_angle * 55 * M_PI / 180.0 / 5)
			- gd->y2 * sin(gd->copy_angle * 55 * M_PI / 180.0 / 5);
		gd->y2 = tmp * sin(gd->copy_angle * 55 * M_PI / 180.0 / 5)
			+ gd->y2 * cos(gd->copy_angle * 55 * M_PI / 180.0 / 5);
	}
}

void	front_back_move(int key, t_data *gd)
{
	if (key == 119)
	{
		gd->pos_y += (gd->x2 * sin(gd->copy_angle)
				+ gd->y2 * cos(gd->copy_angle)) / (RAY_DISTANCE / 2) * 5;
		gd->pos_x += (gd->x2 * cos(gd->copy_angle)
				- gd->y2 * sin(gd->copy_angle)) / (RAY_DISTANCE / 2) * 5;
	}
	else if (key == 115)
	{
		gd->pos_y -= (gd->x2 * sin(gd->copy_angle)
				+ gd->y2 * cos(gd->copy_angle)) / (RAY_DISTANCE / 2) * 5;
		gd->pos_x -= (gd->x2 * cos(gd->copy_angle)
				- gd->y2 * sin(gd->copy_angle)) / (RAY_DISTANCE / 2) * 5;
	}
}

int	not_to_close(int centre_x, int centre_y, double rayon, t_data *gd)
{
	double	angle_degrees;
	double	angle_radians;
	int		x;
	int		y;

	angle_degrees = 0;
	while (angle_degrees < 360)
	{
		angle_radians = angle_degrees * (M_PI / 180.0);
		x = centre_x + (int)(rayon * cos(angle_radians));
		y = centre_y + (int)(rayon * sin(angle_radians));
		if (!collision(gd, x, y))
			return (printf("ca touche: %d | %d\n", x, y), 0);
		angle_degrees += 1;
	}
	return (1);
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
	if (!not_to_close(gd->pos_x, gd->pos_y, 10, gd))
	{
		gd->pos_x = tmp_x;
		gd->pos_y = tmp_y;
	}
	draw_floor(gd);
	draw_player_view(gd);
	mlx_put_image_to_window(gd->mlx, gd->win, gd->pixel.img, 0, 0);
	return (0);
}
