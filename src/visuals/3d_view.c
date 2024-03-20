/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:22:01 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/20 16:12:46 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	draw_floor(t_data *gd)
{
	int			i;
	int			j;
	uint32_t	sky;
	uint32_t	floor;

	i = 0;
	sky = convert_into_hexa(gd->sky_color);
	floor = convert_into_hexa(gd->floor_color);
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT / 2)
			put_pixel_to_image(gd, i, j++, sky);
		while (j < WINDOW_HEIGHT)
			put_pixel_to_image(gd, i, j++, floor);
		i++;
	}
}

void	draw_vertical_line(t_data *game_data, float dist, int ray)
{
	float	height;
	int		i;
	int		pixel;
	float	ray_angle;

	if (dist == -1)
		return ;
	ray_angle = (ray / (float)WINDOW_WIDTH - 0.5) * (69 * M_PI / 180);
	height = (30 * WINDOW_HEIGHT) / (dist * cos(ray_angle));
	if (height >= 1080)
		height = 1080;
	i = 0;
	while (i < height)
	{
		pixel = get_pixel_color(game_data, 0, i / height * 1080, ray % 72);
		put_pixel_to_image(game_data, (WINDOW_WIDTH / 1920) * ray,
			((WINDOW_HEIGHT / 2) - height / 2) + i, pixel);
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

int	get_pixel_color(t_data *gd, int x, int y, int ray)
{
	char	*dst;

	dst = gd->tex.addr[ray] + (y * gd->tex.line_length
			+ x * (gd->tex.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
