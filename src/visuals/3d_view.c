/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:22:01 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/19 14:13:44 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	draw_floor(t_data *gd)
{
	int			i;
	uint32_t	sky;
	uint32_t	floor;

	i = 0;
	sky = convert_into_hexa(gd->sky_color);
	floor = convert_into_hexa(gd->floor_color);
	while (i < WINDOW_WIDTH)
	{
		other_draw_line(gd, i, 0, i, WINDOW_HEIGHT / 2, sky);
		other_draw_line(gd, i, WINDOW_HEIGHT / 2, i, WINDOW_HEIGHT, floor);
		i++;
	}
}

void	draw_vertical_line(t_data *game_data, float dist, int ray)
{
	float	height;
	int		y1;
	int		x;
	int		i;
	//int side = 72;

	if (dist == -1)
		return ;
	float ray_angle = (ray / (float)WINDOW_WIDTH - 0.5) * (69 * M_PI / 180);
	height = (40 * WINDOW_HEIGHT) / (dist * cos(ray_angle));
	//height = (30 * WINDOW_HEIGHT) / dist;
	y1 = (WINDOW_HEIGHT / 2) - height / 2;
	x = (WINDOW_WIDTH / 1920) * ray;
	i = 0;
	void *final = new_display(game_data,game_data->gi_data,72,height, ray);
	while (i < 2)
	{
		//other_draw_line(game_data, x + i, y1, x + i, y1 + height, ORANGE_COLOR);
		mlx_put_image_to_window(game_data->mlx,game_data->win,final,x+i,y1);
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
