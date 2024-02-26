/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:13:58 by tmalidi           #+#    #+#             */
/*   Updated: 2024/02/26 19:55:24 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

float calc_dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void    line(t_data *gd,int x1,int y1,int x2,int y2,int color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int err = dx - dy;
    
    while (1)
    {
        put_pixel_to_image(gd,x1,y1,color);
        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += gd->sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += gd->sy;
        }
    }
}

float other_draw_line(t_data *gd, int x1, int y1, int x2, int y2, int color)
{
    if (x1 < x2)
        gd->sx = 1;
    else
        gd->sx = -1;

    if (y1 < y2)
        gd->sy = 1;
    else
        gd->sy = -1;
    line(gd,x1,y1,x2,y2,color);
    if (x1 != x2 || y1 != y2)
    {
        printf("distance == %f\n", calc_dist(gd->pos_x,gd->pos_y,x1,y1));
        return (calc_dist(gd->pos_x,gd->pos_y,x1,y1));
    }
    return (-1);
}

float draw_line(t_data *gd, int x1, int y1, int x2, int y2, int color)
{
    (void)color;
    
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    if (x1 < x2)
        gd->sx = 1;
    else
        gd->sx = -1;

    if (y1 < y2)
        gd->sy = 1;
    else
        gd->sy = -1;

    int err = dx - dy;
    while ((x1 < 400 || y1 < 200 +1) || (x1 > 440 - 2 || y1 > 240 - 1))
    {
        //mlx_pixel_put(gd->mlx, gd->win, x1, y1, color);
        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += gd->sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += gd->sy;
        }
    }
    if (x1 != x2 || y1 != y2)
    {
        printf("distance == %f\n", calc_dist(gd->pos_x,gd->pos_y,x1,y1));
        return (calc_dist(gd->pos_x,gd->pos_y,x1,y1));
    }
    return (-1);
}