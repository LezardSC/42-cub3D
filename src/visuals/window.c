/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:28:46 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/01 15:11:33 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void draw_player_view(t_data *game_data)
{
    int i;
    double cp_x = game_data->x2;
    double cp_y = game_data->y2;
    double radius = 1920.0;

    i = 0;
    while (i < 73)
    {
        double temp_cp_x = cp_x;
        double temp_cp_y = cp_y;
        cp_x = temp_cp_x * cos(game_data->angle) - temp_cp_y * sin(game_data->angle);
        cp_y = temp_cp_x * sin(game_data->angle) + temp_cp_y * cos(game_data->angle);
        cp_x = (cp_x / sqrt(cp_x * cp_x + cp_y * cp_y)) * radius;
        cp_y = (cp_y / sqrt(cp_x * cp_x + cp_y * cp_y)) * radius;
        draw_vertical_line(game_data,draw_line(game_data, game_data->pos_x, game_data->pos_y, game_data->pos_x + cp_x, game_data->pos_y + cp_y, 0xFF2D00),i);
        i++;
    }
}

void making_map(t_data *gd)
{
    int side;
    int height;

    side = 1920 / (gd->max_x + 1);
    height = 1080 / (gd->max_y  + 1);
    while (side < 1920)
    {
        draw_line_for_wall(gd,side,0,side,1080,0xFF2D00);
        side += 1920 / (gd->max_x + 1);
    }
    while (height < 1080)
    {
        draw_line_for_wall(gd,0,height,1920,height,0xFF2D00);
        height += 1080 / (gd->max_y  + 1);
    }
}

int collision(t_data *gd, int x, int y)
{
    float case_height;
    float case_width;
    int column_index;
    int line_index;

    case_width = 1920 / gd->max_x;
    case_height = 1080 / gd->max_y;
    column_index = (int)(x/case_width);
    line_index = (int)(y/case_height);
    if (gd->map[line_index][column_index] == '1')
        return (0);
    //printf("ligne = [%d] | colonne = [%d] [%d] [%d] \n", line_index,column_index,gd->max_x,gd->max_y);
    return 1;
}

void ft_put_windows(t_data *game_data)
{
    //initilisation des données
    game_data->angle = 1 * M_PI / 180.0;
    game_data->copy_angle = 1 * 90/3 * M_PI / 180.0;
    game_data->pos_x = 300;
    game_data->pos_y = 300;
    game_data->x2 = game_data->pos_x + 1920;
    game_data->y2 = game_data->pos_y;
    
    //init de la fenetre
    //game_data->mlx = mlx_init();
    //game_data->win2 = mlx_new_window(game_data->mlx,1920,1080,"Cube3Drs");
    //game_data->win = mlx_new_window(game_data->mlx,1920,1080,"Cube3Dls");
    //making_map(game_data);
    game_data->gi = mlx_new_image(game_data->mlx,1920,1080);
    game_data->addr = mlx_get_data_addr(game_data->gi,&game_data->bpp,&game_data->sl,&game_data->endian);
    draw_player_view(game_data);
    mlx_key_hook(game_data->win, ft_key, game_data);
    mlx_hook(game_data->win, 17, 1l << 0, exit_game, game_data);
    mlx_loop(game_data->mlx);
}