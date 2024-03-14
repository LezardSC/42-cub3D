/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:28:46 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/14 16:02:22 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void draw_player_view(t_data *game_data)
{
    int i;
    double cp_x = game_data->x2;
    double cp_y = game_data->y2;
    double radius = WINDOW_WIDTH;

    i = 0;
    //printf("[%d][%d]\n", game_data->pos_x, game_data->pos_y);
    while (i < 73)
    {
        double temp_cp_x = cp_x;
        double temp_cp_y = cp_y;
        cp_x = temp_cp_x * cos(game_data->angle) - temp_cp_y * sin(game_data->angle);
        cp_y = temp_cp_x * sin(game_data->angle) + temp_cp_y * cos(game_data->angle);
        cp_x = (cp_x / sqrt(cp_x * cp_x + cp_y * cp_y)) * radius;
        cp_y = (cp_y / sqrt(cp_x * cp_x + cp_y * cp_y)) * radius;
        draw_vertical_line(game_data,draw_line(game_data, game_data->pos_x, game_data->pos_y, game_data->pos_x + cp_x, game_data->pos_y + cp_y, ORANGE_COLOR),i);
        i++;
    }
}

void making_map(t_data *gd)
{
    int side;
    int height;

    side = WINDOW_WIDTH / (gd->max_x + 1);
    height = WINDOW_HEIGHT / (gd->max_y  + 1);
    while (side < WINDOW_WIDTH)
    {
        draw_line_for_wall(gd,side,0,side,WINDOW_HEIGHT,ORANGE_COLOR);
        side += WINDOW_WIDTH / (gd->max_x + 1);
    }
    while (height < WINDOW_HEIGHT)
    {
        draw_line_for_wall(gd,0,height,WINDOW_WIDTH,height,ORANGE_COLOR);
        height += WINDOW_HEIGHT / (gd->max_y  + 1);
    }
}

int collision(t_data *gd, int x, int y)
{
    float case_height;
    float case_width;
    int column_index;
    int line_index;

    case_width = WINDOW_WIDTH / gd->max_x;
    case_height = WINDOW_HEIGHT / gd->max_y;
    column_index = (int)(x/case_width);
    line_index = (int)(y/case_height);
    //printf("[%d] [%d]", line_index, column_index);
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
    game_data->x2 = game_data->pos_x + WINDOW_WIDTH;
    game_data->y2 = game_data->pos_y;
    
    //mlx_key_hook(game_data->win, ft_key, game_data);
    //mlx_hook(game_data->win, 17, 1l << 0, exit_game, game_data);
    mlx_hook(game_data->win, 02, 1L << 0, deal_key, game_data);
	mlx_hook(game_data->win, 17, 0, close_win, game_data);
    mlx_key_hook(game_data->win, key_release, game_data);
    mlx_loop_hook(game_data->mlx, move_player, game_data);
    mlx_loop(game_data->mlx);
}