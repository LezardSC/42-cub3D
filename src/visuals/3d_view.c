/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:22:01 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/19 19:01:53 by tmalidi          ###   ########.fr       */
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
	int pixel;

	if (dist == -1)
		return ;
	float ray_angle = (ray / (float)WINDOW_WIDTH - 0.5) * (69 * M_PI / 180);
	height = (30 * WINDOW_HEIGHT) / (dist * cos(ray_angle));
	if (height >= 1080)
		height = 1080;
	y1 = (WINDOW_HEIGHT / 2) - height / 2;
	x = (WINDOW_WIDTH / 1920) * ray;
	i = 0;
	game_data->tex.img = new_display(game_data,game_data->gi_data,1,height, ray);
	game_data->tex.addr = mlx_get_data_addr(game_data->tex.img,&game_data->tex.bits_per_pixel,&game_data->tex.line_length,&game_data->tex.endian);
	while (i < height)
	{
		pixel = get_pixel_color(game_data,0,i);
		put_pixel_to_image(game_data,x,y1++,pixel);
		i++;
	}
	mlx_destroy_image(game_data->mlx,game_data->tex.img);
}

void	put_pixel_to_image(t_data *gd, int x, int y, int color)
{
	char	*dst;

	dst = gd->pixel.addr + (y * gd->pixel.line_length
			+ x * (gd->pixel.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_data *gd, int x, int y)
{
	char    *dst;

    dst = gd->tex.addr + (y * gd->tex.line_length + x * (gd->tex.bits_per_pixel / 8));
    return (*(unsigned int *)dst);
}


