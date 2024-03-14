/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:22:01 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/14 16:44:27 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	draw_floor(t_data *gd)
{
	int	i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		other_draw_line(gd, i, 0, i, WINDOW_HEIGHT / 2, BLUE_COLOR);
		other_draw_line(gd, i, WINDOW_HEIGHT / 2, i, WINDOW_HEIGHT, GREY_COLOR);
		i++;
	}
}

void	draw_vertical_line(t_data *game_data, float dist, int ray)
{
	float	height;
	float	y1;
	int		x;
	int		i;

	if (dist == -1)
		return ;
	height = (30 * WINDOW_HEIGHT) / dist;
	y1 = (WINDOW_HEIGHT / 2) - height / 2;
	x = (WINDOW_WIDTH / 73) * ray;
	i = 0;
	while (i < 30)
	{
		other_draw_line(game_data, x + i, y1, x + i, y1 + height, ORANGE_COLOR);
		i++;
	}
}

void	put_pixel_to_image(t_data *gd, int x, int y, int color)
{
	char	*dst;

	dst = gd->pixel.addr + (y * gd->pixel.line_length
			+ x * (gd->pixel.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
