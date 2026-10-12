/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:54:28 by tmalidi           #+#    #+#             */
/*   Updated: 2024/04/22 17:01:39 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	not_to_close(int centre_x, int centre_y, double rayon, t_data *gd)
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
			return (0);
		angle_degrees += 1;
	}
	return (1);
}

void	move_dir(t_data *gd, double offset, double dist)
{
	double	dx;
	double	dy;
	double	len;

	dx = gd->x2 * cos(gd->copy_angle + offset)
		- gd->y2 * sin(gd->copy_angle + offset);
	dy = gd->x2 * sin(gd->copy_angle + offset)
		+ gd->y2 * cos(gd->copy_angle + offset);
	len = sqrt(dx * dx + dy * dy);
	if (len == 0)
		return ;
	dx = dx / len * dist;
	dy = dy / len * dist;
	gd->pos_x += dx;
	if (!not_to_close(gd->pos_x, gd->pos_y, PLAYER_RADIUS, gd))
		gd->pos_x -= dx;
	gd->pos_y += dy;
	if (!not_to_close(gd->pos_x, gd->pos_y, PLAYER_RADIUS, gd))
		gd->pos_y -= dy;
}

void	rotate_view(t_data *gd, double a)
{
	double	tmp;

	tmp = gd->x2;
	gd->x2 = gd->x2 * cos(a) - gd->y2 * sin(a);
	gd->y2 = tmp * sin(a) + gd->y2 * cos(a);
}

int	ft_key(int key, t_data *gd)
{
	if (key == ESC)
		exit_game(gd);
	draw_floor(gd);
	draw_player_view(gd);
	mlx_put_image_to_window(gd->mlx, gd->win, gd->pixel.img, 0, 0);
	return (0);
}
