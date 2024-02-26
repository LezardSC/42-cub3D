/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:28:46 by tmalidi           #+#    #+#             */
/*   Updated: 2024/02/26 19:57:15 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include <stdio.h>

float calculerDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

float other_draw_line(t_data *gd, int x1, int y1, int x2, int y2, int color)
{
    (void)color;
    
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx, sy;

    if (x1 < x2)
        sx = 1;
    else
        sx = -1;

    if (y1 < y2)
        sy = 1;
    else
        sy = -1;

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
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
    if (x1 != x2 || y1 != y2)
    {
        printf("distance == %f\n", calculerDistance(gd->pos_x,gd->pos_y,x1,y1));
        return (calculerDistance(gd->pos_x,gd->pos_y,x1,y1));
    }
    return (-1);
        //draw_vertical_line(gd,calculerDistance(gd->pos_x,gd->pos_y,x1,y1));
}

float draw_line(t_data *gd, int x1, int y1, int x2, int y2, int color)
{
    (void)color;
    
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx, sy;

    if (x1 < x2)
        sx = 1;
    else
        sx = -1;

    if (y1 < y2)
        sy = 1;
    else
        sy = -1;

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
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
    if (x1 != x2 || y1 != y2)
    {
        printf("distance == %f\n", calculerDistance(gd->pos_x,gd->pos_y,x1,y1));
        return (calculerDistance(gd->pos_x,gd->pos_y,x1,y1));
    }
    return (-1);
}

void draw_player_view(t_data *game_data)
{
    int i;
    double cp_x = game_data->x2;
    double cp_y = game_data->y2;
    double radius = 720.0;

    i = 1;
    draw_line(game_data, 399,200,399,240,0x0000FF);
    draw_line(game_data, 439,200,439,240,0x0000FF);
    draw_line(game_data, 399,240,439,240,0x0000FF);
    draw_line(game_data, 399,200,439,200,0x0000FF);
    while (i < 72)
    {
        
        double temp_cp_x = cp_x;
        double temp_cp_y = cp_y;
        cp_x = temp_cp_x * cos(game_data->angle) - temp_cp_y * sin(game_data->angle);
        cp_y = temp_cp_x * sin(game_data->angle) + temp_cp_y * cos(game_data->angle);
        cp_x = (cp_x / sqrt(cp_x * cp_x + cp_y * cp_y)) * radius;
        cp_y = (cp_y / sqrt(cp_x * cp_x + cp_y * cp_y)) * radius;
        if (i > 2)
        {
            //draw_line(game_data, game_data->pos_x, game_data->pos_y, game_data->pos_x + cp_x, game_data->pos_y + cp_y, 0xFF2D00);
            draw_vertical_line(game_data,draw_line(game_data, game_data->pos_x, game_data->pos_y, game_data->pos_x + cp_x, game_data->pos_y + cp_y, 0xFF2D00),i);
        }
        i++;
    }
}

void draw_circle(t_data *game_data, int xc, int yc, int radius, int color)
{
    int x = radius;
    int y = 0;
    int radiusError = 1 - x;

    while (x >= y)
    {
        // Tracer les rayons du cercle vers chaque point sur le cercle (sens horaire)
        draw_line(game_data, xc, yc, xc + x, yc - y, color);
        draw_line(game_data, xc, yc, xc - x, yc - y, color);
        draw_line(game_data, xc, yc, xc + x, yc + y, color);
        draw_line(game_data, xc, yc, xc - x, yc + y, color);
        draw_line(game_data, xc, yc, xc + y, yc + x, color);
        draw_line(game_data, xc, yc, xc - y, yc + x, color);
        draw_line(game_data, xc, yc, xc + y, yc - x, color);
        draw_line(game_data, xc, yc, xc - y, yc - x, color);

        y++;

        if (radiusError < 0)
            radiusError += 2 * y + 1;
        else
        {
            x--;
            radiusError += 2 * (y - x) + 1;
        }
    }
}

void ft_put_windows(t_data *game_data)
{
    //initilisation des données
    game_data->angle = 1 * M_PI / 180.0;
    game_data->copy_angle = 1 * 90/3 * M_PI / 180.0;
    game_data->pos_x = 100;
    game_data->pos_y = 0 + 100;
    game_data->x2 = 200 + 100;
    game_data->y2 = 0 + 100;
    
    //init de la fenetre
    game_data->mlx = mlx_init();
    //game_data->win = mlx_new_window(game_data->mlx,720,480,"Cube3D");
    game_data->win2 = mlx_new_window(game_data->mlx,720,480,"Cube3D");
    game_data->gi = mlx_new_image(game_data->mlx,720,480);
    game_data->addr = mlx_get_data_addr(game_data->gi,&game_data->bpp,&game_data->sl,&game_data->endian);
    
    //position initiale du joueur
    //draw_player_view(game_data);
    
    //fonction de deplacement
    mlx_key_hook(game_data->win2, ft_key, game_data);
    
    mlx_hook(game_data->win2, 17, 1l << 0, exit_game, game_data);
    mlx_loop(game_data->mlx);
}