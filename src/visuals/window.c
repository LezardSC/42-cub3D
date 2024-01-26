/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:28:46 by tmalidi           #+#    #+#             */
/*   Updated: 2024/01/26 22:41:36 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

//exit

int exit_game(t_data *game_data)
{
    mlx_destroy_window(game_data->mlx, game_data->win);
    mlx_destroy_display(game_data->mlx);
    exit(0);
}

//trace un rayon

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

//trace un demi cercle

void draw_circle(t_data *game_data, int xc, int yc, int radius, int color)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (x <= y)
    {
        // Tracer les rayons du cercle vers chaque point sur la moitié supérieure du cercle
        draw_line(game_data, xc, yc, xc - y, yc - x, color);
        draw_line(game_data, xc, yc, xc - x, yc - y, color);
        draw_line(game_data, xc, yc, xc + x, yc - y, color);
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

//pour les input

int	ft_key(int key, t_data *gd)
{
	if (key == 65307)
		exit_game(gd);
    if (key == 119 || key == 65362)
    {
        mlx_clear_window(gd->mlx, gd->win);
        draw_circle(gd,gd->pos_x , --gd->pos_y , 200, 0xFF2D00);
    }
    else if (key == 100 || key == 65363)
    {
        mlx_clear_window(gd->mlx, gd->win);
        draw_circle(gd,++gd->pos_x , gd->pos_y , 200, 0xFF2D00);
    }
    else if (key == 115 || key == 65364)
    {
        mlx_clear_window(gd->mlx, gd->win);
        draw_circle(gd,gd->pos_x , ++gd->pos_y , 200, 0xFF2D00);
    }
    else if (key == 97 || key == 65361)
    {
        mlx_clear_window(gd->mlx, gd->win);
        draw_circle(gd,--gd->pos_x , gd->pos_y , 200, 0xFF2D00);
    }
	return (0);
}

//fonction final

void ft_put_windows(t_data *game_data)
{
    game_data->pos_x = 100;
    game_data->pos_y = 100;
    
    game_data->mlx = mlx_init();
    game_data->win = mlx_new_window(game_data->mlx,720,480,"Cube3D");
    mlx_key_hook(game_data->win, ft_key, game_data);
    mlx_hook(game_data->win, 17, 1l << 0, exit_game, game_data);
    mlx_loop(game_data->mlx);
    
}