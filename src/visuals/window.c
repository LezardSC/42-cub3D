/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:28:46 by tmalidi           #+#    #+#             */
/*   Updated: 2024/01/30 11:20:42 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include <stdio.h>

int exit_game(t_data *game_data)
{
    mlx_destroy_window(game_data->mlx, game_data->win);
    mlx_destroy_display(game_data->mlx);
    exit(0);
}

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

/*void draw_player_view(t_data *game_data)
{
    int i;
    double cp_x = game_data->x2;
    double cp_y = game_data->y2;
    double length;

    i = 0;
    while (i < 4)
    {
        cp_x = cp_x*cos(game_data->a) - cp_y*sin(game_data->a);
        cp_y = cp_x*sin(game_data->a) + cp_y*cos(game_data->a);
        length = sqrt(cp_x * cp_x + cp_y * cp_y);
        cp_x = (cp_x / length) * 50;
        cp_y = (cp_y / length) * 50;
        draw_line(game_data, game_data->pos_x, game_data->pos_y,cp_x,cp_y,0xFF2D00);
        i++;
    }
}*/

void draw_player_view(t_data *game_data)
{
    int i;
    double cp_x = game_data->x2;
    double cp_y = game_data->y2;

    // Calcul de la longueur du rayon
    double radius = 200.0; // Remplacez cette valeur par la longueur souhaitée

    i = 1;
    while (i < 70)
    {
        // Copie temporaire des coordonnées
        double temp_cp_x = cp_x;
        double temp_cp_y = cp_y;

        // Transformation de rotation
        cp_x = temp_cp_x * cos(game_data->a) - temp_cp_y * sin(game_data->a);
        cp_y = temp_cp_x * sin(game_data->a) + temp_cp_y * cos(game_data->a);

        // Normalisation de la longueur du rayon
        double length = sqrt(cp_x * cp_x + cp_y * cp_y);
        cp_x = (cp_x / length) * radius;
        cp_y = (cp_y / length) * radius;

        // Dessiner la ligne
        draw_line(game_data, game_data->pos_x, game_data->pos_y, game_data->pos_x + cp_x, game_data->pos_y + cp_y, 0xFF2D00);

        i++;
    }
}

int	ft_key(int key, t_data *gd)
{
	if (key == 65307)
		exit_game(gd);
    if (key == 119 || key == 65362)
    {
        gd->pos_y += (gd->x2*sin(gd->c) + gd->y2*cos(gd->c)) / 4;
        gd->pos_x += (gd->x2*cos(gd->c) - gd->y2*sin(gd->c)) / 4;
        mlx_clear_window(gd->mlx, gd->win);
        draw_player_view(gd);
    }
    else if (key == 100 || key == 65363)
    {
        gd->x2 = gd->x2*cos(gd->a) - gd->y2*sin(gd->a);
        gd->y2 = gd->x2*sin(gd->a) + gd->y2*cos(gd->a);
        mlx_clear_window(gd->mlx, gd->win);
        draw_player_view(gd); 
    }
    else if (key == 115 || key == 65364)
    {
        gd->pos_y -= (gd->x2*sin(gd->c) + gd->y2*cos(gd->c)) / 4;
        gd->pos_x -= (gd->x2*cos(gd->c) - gd->y2*sin(gd->c)) / 4;
        mlx_clear_window(gd->mlx, gd->win);
        draw_player_view(gd);
    }
    else if (key == 97 || key == 65361)
    {
        gd->x2 = gd->x2*cos(gd->a) + gd->y2*sin(gd->a);
        gd->y2 = -gd->x2*sin(gd->a) + gd->y2*cos(gd->a);
        mlx_clear_window(gd->mlx, gd->win);
        draw_player_view(gd);
    }
    printf(">>>>>>>%f | %f = %f\n", gd->x2, gd->y2, gd->x2 + gd->y2);
	return (0);
}

void ft_put_windows(t_data *game_data)
{

    game_data->a = 1 * M_PI / 180.0;
    game_data->c = 1 * 90/3 * M_PI / 180.0;
    game_data->pos_x = 200;
    game_data->pos_y = 200;
    game_data->x2 = 200;
    game_data->y2 = 0;
    
    game_data->mlx = mlx_init();
    game_data->win = mlx_new_window(game_data->mlx,720,480,"Cube3D");
    //draw_line(game_data, x1, y1, j * cos(a) - x * sin(a) , j * sin(a) + x * cos(a),0xFF2D00);
    //draw_circle(game_data, 300, 300, 40, 0xFF2D00);
    mlx_key_hook(game_data->win, ft_key, game_data);
    mlx_hook(game_data->win, 17, 1l << 0, exit_game, game_data);
    mlx_loop(game_data->mlx);
    
}