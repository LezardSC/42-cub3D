/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:28:46 by tmalidi           #+#    #+#             */
/*   Updated: 2024/01/30 16:37:54 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int exit_game(t_data *game_data)
{
    mlx_destroy_window(game_data->mlx, game_data->win);
    mlx_destroy_display(game_data->mlx);
    exit(0);
}

/*void draw_line(t_data *gd, int x1, int y1, int x2, int y2, int color)
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
}*/

void draw_line(t_data *gd, int x1, int y1, int x2, int y2, int color)
{
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

void draw_player_view(t_data *game_data)
{
    int i;
    double cp_x = game_data->x2;
    double cp_y = game_data->y2;
    double radius = 200.0;

    i = 1;
    while (i < 70)
    {
        double temp_cp_x = cp_x;
        double temp_cp_y = cp_y;
        cp_x = temp_cp_x * cos(game_data->angle) - temp_cp_y * sin(game_data->angle);
        cp_y = temp_cp_x * sin(game_data->angle) + temp_cp_y * cos(game_data->angle);
        cp_x = (cp_x / sqrt(cp_x * cp_x + cp_y * cp_y)) * radius;
        cp_y = (cp_y / sqrt(cp_x * cp_x + cp_y * cp_y)) * radius;
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
        gd->pos_y += (gd->x2*sin(gd->copy_angle) + gd->y2*cos(gd->copy_angle)) / 4;
        gd->pos_x += (gd->x2*cos(gd->copy_angle) - gd->y2*sin(gd->copy_angle)) / 4;
    }
    else if (key == 100 || key == 65363)
    {
        gd->x2 = gd->x2*cos(gd->angle) - gd->y2*sin(gd->angle);
        gd->y2 = gd->x2*sin(gd->angle) + gd->y2*cos(gd->angle); 
    }
    else if (key == 115 || key == 65364)
    {
        gd->pos_y -= (gd->x2*sin(gd->copy_angle) + gd->y2*cos(gd->copy_angle)) / 4;
        gd->pos_x -= (gd->x2*cos(gd->copy_angle) - gd->y2*sin(gd->copy_angle)) / 4;
    }
    else if (key == 97 || key == 65361)
    {
        gd->x2 = gd->x2*cos(gd->angle) + gd->y2*sin(gd->angle);
        gd->y2 = -gd->x2*sin(gd->angle) + gd->y2*cos(gd->angle);
    }
    mlx_clear_window(gd->mlx, gd->win);
    draw_player_view(gd);
	return (0);
}

void ft_put_windows(t_data *game_data)
{
    //initilisation des données
    game_data->angle = 1 * M_PI / 180.0;
    game_data->copy_angle = 1 * 90/3 * M_PI / 180.0;
    game_data->pos_x = 200;
    game_data->pos_y = 200;
    game_data->x2 = 200;
    game_data->y2 = 0;
    
    //init de la fenetre
    game_data->mlx = mlx_init();
    game_data->win = mlx_new_window(game_data->mlx,720,480,"Cube3D");

    //position initiale du joueur
    draw_player_view(game_data);
    
    //fonction de deplacement
    mlx_key_hook(game_data->win, ft_key, game_data);
    
    mlx_hook(game_data->win, 17, 1l << 0, exit_game, game_data);
    mlx_loop(game_data->mlx);
    
}