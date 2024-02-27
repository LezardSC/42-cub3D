/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:55:32 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/31 17:33:31 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

/*
Here I have the function to draw a pixel, and also one for a square, for the walls of the minimap, and two to draw a circle, for the
player.
*/

void	my_mlx_pixel_put_map(t_drawmap *drawmap, int x, int y, int color)
{
	char	*dst;

	dst = drawmap->addr + (y * drawmap->line_length + x
			* (drawmap->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put_mini(t_drawmm *drawmm, int x, int y, int color)
{
	char	*dst;

	dst = drawmm->addr + (y * drawmm->line_length + x
			* (drawmm->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_square_put(t_drawmm *drawmm, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < drawmm->size)
	{
		j = 0;
		while (j < drawmm->size)
		{
			my_mlx_pixel_put_mini(drawmm, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

static void	draw_circle(t_data *param, int x, int y, int color)
{
	int	i;

	i = param->player.pos_x - x;
	while (i <= param->player.pos_x + x)
	{
		my_mlx_pixel_put_mini(&param->drawmm, i, param->player.pos_y + y, color);
		my_mlx_pixel_put_mini(&param->drawmm, i, param->player.pos_y - y, color);
		i++;
	}
	i = param->player.pos_x - y;
	while (i <= param->player.pos_x + y)
	{
		my_mlx_pixel_put_mini(&param->drawmm, i, param->player.pos_y + x, color);
		my_mlx_pixel_put_mini(&param->drawmm, i, param->player.pos_y - x, color);
		i++;
	}
}

void	my_mlx_circle_put(t_data *param, int color)
{
	int	x;
	int	y;
	int	radius_error;

	x = param->drawmm.radius;
	y = 0;
	radius_error = 1 - x;
	while (x >= y)
	{
		draw_circle(param, x, y, color);
		y++;
		if (radius_error < 0)
			radius_error += 2 * y + 1;
		else
		{
			x--;
			radius_error += 2 * (y - x + 1);
		}
	}
}
