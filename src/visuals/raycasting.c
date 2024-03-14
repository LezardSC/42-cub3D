/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:13:58 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/14 17:38:57 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

float calc_dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void	init_line_data(t_line_data *data, int x1, int y1, int x2, int y2)
{
	data->dx = abs(x2 - x1);
	data->dy = abs(y2 - y1);
	if (x1 < x2)
		data->sx = 1;
	else
		data->sx = -1;
	if (y1 < y2)
		data->sy = 1;
	else
		data->sy = -1;
	data->err = data->dx - data->dy;
}

float other_draw_line(t_data *gd, int x1, int y1, int x2, int y2, int color)
{
    t_line_data data;
	
	init_line_data(&data, x1, y1, x2, y2);
    while (1)
    {
        if ((y1 < WINDOW_HEIGHT && y1 > 0) && (y1 > MINIMAP_HEIGHT || x1 > MINIMAP_WIDTH))
            put_pixel_to_image(gd,x1,y1,color);
        if ((x1 == x2 && y1 == y2))
            break;
        data.e2 = 2 * data.err;
        if (data.e2 > -data.dy)
        {
            data.err -= data.dy;
            x1 += data.sx;
        }
        if (data.e2 < data.dx)
        {
            data.err += data.dx;
            y1 += data.sy;
        }
    }
    if (x1 != x2 || y1 != y2)
        return (calc_dist(gd->pos_x,gd->pos_y,x1,y1));
    return (-1);
}

float draw_line(t_data *gd, int x1, int y1, int x2, int y2, int color)
{
    (void)color;
    t_line_data data;
	
	init_line_data(&data, x1, y1, x2, y2);
    while (1)
    {
        if ((x1 == x2 && y1 == y2) || !collision(gd,x1,y1))
            break;
        data.e2 = 2 * data.err;
        if (data.e2 > -data.dy)
        {
            data.err -= data.dy;
            x1 += data.sx;
        }
        if (data.e2 < data.dx)
        {
            data.err += data.dx;
            y1 += data.sy;
        }
    }
    if (x1 != x2 || y1 != y2)
        return (calc_dist(gd->pos_x,gd->pos_y,x1,y1));
    return (-1);
}

float draw_line_for_wall(t_data *gd, int x1, int y1, int x2, int y2, int color)
{
    (void)color;
    
    t_line_data data;
	
	init_line_data(&data, x1, y1, x2, y2);
    while (1)
    {
        if (x1 == x2 && y1 == y2)
            break;

        data.e2 = 2 * data.err;
        if (data.e2 > -data.dy)
        {
            data.err -= data.dy;
            x1 += data.sx;
        }
        if (data.e2 < data.dx)
        {
            data.err += data.dx;
            y1 += data.sy;
        }
    }
    if (x1 != x2 || y1 != y2)
        return (calc_dist(gd->pos_x,gd->pos_y,x1,y1));
    return (-1);
}