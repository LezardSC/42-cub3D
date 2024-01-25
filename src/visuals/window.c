/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:28:46 by tmalidi           #+#    #+#             */
/*   Updated: 2024/01/25 11:20:20 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int exit_game(t_data *game_data)
{
    mlx_destroy_window(game_data->mlx, game_data->win);
    mlx_destroy_display(game_data->mlx);
    exit(0);
}

int	ft_key(int key, t_data *gd)
{
	if (key == 65307)
		exit_game(gd);
	return (0);
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

void ft_put_windows(t_data *game_data)
{
    //int i = 0;
    //int y = 0;
    //int j = 0;
    //int x = 0;
    game_data->mlx = mlx_init();
    game_data->win = mlx_new_window(game_data->mlx,720,480,"Cube3D");
    draw_line(game_data, 10, 10, 200, 100, 0xFFFFFF);
    draw_line(game_data, 10, 10, 200, 200, 0xFFFFFF);
    mlx_key_hook(game_data->win, ft_key, game_data);
    mlx_hook(game_data->win, 17, 1l << 0, exit_game, game_data);
    mlx_loop(game_data->mlx);
    
}