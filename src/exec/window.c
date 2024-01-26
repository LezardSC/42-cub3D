/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:28:46 by tmalidi           #+#    #+#             */
/*   Updated: 2024/01/26 23:02:39 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void draw_line(t_data *gd, int x1, int y1, int x2, int y2, int color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_pixel_put(gd->mlx, gd->win, x1, y1, color);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

/*void draw_circle(t_data *game_data, int xc, int yc, int radius, int color)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (x <= y)
    {
        // Tracer les rayons du cercle vers chaque point sur le cercle
        draw_line(game_data, xc, yc, xc + x, yc + y, color);
        draw_line(game_data, xc, yc, xc - x, yc + y, color);
        draw_line(game_data, xc, yc, xc + x, yc - y, color);
        draw_line(game_data, xc, yc, xc - x, yc - y, color);
        draw_line(game_data, xc, yc, xc + y, yc + x, color);
        draw_line(game_data, xc, yc, xc - y, yc + x, color);
        draw_line(game_data, xc, yc, xc + y, yc - x, color);
        draw_line(game_data, xc, yc, xc - y, yc - x, color);

        if (d < 0)
            d = d + 4 * x + 6;
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}*/

/*void draw_circle(t_data *game_data, int xc, int yc, int radius, int color, int start_angle)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (x <= y)
    {
        // Calcule l'angle actuel du rayon en radians
        double current_angle = atan2(y, x) * 180 / M_PI;

        // Tracer les rayons du cercle vers chaque point sur le cercle
        if (current_angle >= start_angle)
        {
            draw_line(game_data, xc, yc, xc + x, yc + y, color);
        }

        if (d < 0)
            d = d + 4 * x + 6;
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}*/

void draw_circle(t_data *game_data, int xc, int yc, int radius, int color)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (x <= y)
    {
        // Tracer les rayons du cercle vers chaque point sur la moitié supérieure du cercle
        //draw_line(game_data, xc, yc, xc - y, yc - x, color);
        //draw_line(game_data, xc, yc, xc - x, yc - y, color);
        //draw_line(game_data, xc, yc, xc + x, yc - y, color);
        draw_line(game_data, xc, yc, xc + y, yc - x, color);
        if (d < 0)
            d = d + 4 * x + 6;
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void ft_put_windows(t_data *game_data)
{
    //int i = 0;
    //int y = 0;
    //int j = 0;
    //int x = 0;
    game_data->pos_x = 100;
    game_data->pos_y = 100;
    
    //draw_circle(game_data, 300, 300, 40, 0xFF2D00);
}