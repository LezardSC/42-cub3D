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

void	put_pixel_to_image(t_data *gd, int x, int y, int color)
{
	char	*dst;

	dst = gd->pixel.addr + (y * gd->pixel.line_length
			+ x * (gd->pixel.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_length + x
			* (pixel->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_square_put(t_pixel *pixel, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < pixel->size)
	{
		j = 0;
		while (j < pixel->size)
		{
			my_mlx_pixel_put(pixel, x + i, y + j, color);
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
		my_mlx_pixel_put(&param->pixel, i, param->player.pos_y + y, color);
		my_mlx_pixel_put(&param->pixel, i, param->player.pos_y - y, color);
		i++;
	}
	i = param->player.pos_x - y;
	while (i <= param->player.pos_x + y)
	{
		my_mlx_pixel_put(&param->pixel, i, param->player.pos_y + x, color);
		my_mlx_pixel_put(&param->pixel, i, param->player.pos_y - x, color);
		i++;
	}
}

void	my_mlx_circle_put(t_data *param, int color)
{
	int	x;
	int	y;
	int	radius_error;

	x = param->pixel.radius;
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
