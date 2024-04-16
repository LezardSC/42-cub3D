/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:22:01 by tmalidi           #+#    #+#             */
/*   Updated: 2024/04/16 08:58:29 by tmalidi          ###   ########.fr       */
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

void	draw_texture(t_data *game_data, t_ray_data *ray, int i, float height)
{
	int		pixel;
	double	x;
	double	y;

	pixel = BLACK_COLOR;
	if (!collision(game_data, ray->x, ray->y - 1)
		&& !collision(game_data, ray->x, ray->y + 1))
	{
		if (!collision(game_data, ray->x + 1, ray->y))
			pixel = get_pixel_color(game_data, i
					/ height * WINDOW_HEIGHT, ray->y % TEX_SIDE, EA);
		else
			pixel = get_pixel_color(game_data, i
					/ height * WINDOW_HEIGHT, ray->y % TEX_SIDE, WE);
	}
	else
	{
		if (!collision(game_data, ray->x, ray->y + 1))
			pixel = get_pixel_color(game_data, i
					/ height * WINDOW_HEIGHT, ray->x % TEX_SIDE, SO);
		else
			pixel = get_pixel_color(game_data, i
					/ height * WINDOW_HEIGHT, ray->x % TEX_SIDE, NO);
	}
	x = (WINDOW_WIDTH / WINDOW_WIDTH) * ray->id;
	y = ((WINDOW_HEIGHT / 2) - height / 2) + i;
	if (y < 1080 && y > 0)
		put_pixel_to_image(game_data, x,y, pixel);
}

void	draw_vertical_line(t_data *game_data, t_ray_data *ray)
{
	double	height;
	int		i;
	double	ray_angle;

	if (ray->dist == -1)
		return ;
	ray_angle = (ray->id / (double)WINDOW_WIDTH - 0.5) * (70.0 * M_PI / 180.0);
	height = (80.0 * (double)WINDOW_HEIGHT) / (ray->dist * cos(ray_angle));
	i = 0;
	while (i < height)
	{
		draw_texture(game_data, ray, i, height);
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

int	get_pixel_color(t_data *gd, int y, int ray, int card)
{
	char	*dst;

	dst = 0;
	if (card == NO)
	{
		dst = gd->tex_north.addr[ray] + (y * gd->tex_north.line_length
				+ 0 * (gd->tex_north.bits_per_pixel / 8));
	}
	if (card == SO)
	{
		dst = gd->tex_south.addr[ray] + (y * gd->tex_south.line_length
				+ 0 * (gd->tex_south.bits_per_pixel / 8));
	}
	if (card == EA)
	{
		dst = gd->tex_east.addr[ray] + (y * gd->tex_east.line_length
				+ 0 * (gd->tex_east.bits_per_pixel / 8));
	}
	if (card == WE)
	{
		dst = gd->tex_west.addr[ray] + (y * gd->tex_west.line_length
				+ 0 * (gd->tex_west.bits_per_pixel / 8));
	}
	return (*(unsigned int *)dst);
}
