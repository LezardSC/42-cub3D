/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:28:46 by tmalidi           #+#    #+#             */
/*   Updated: 2024/02/27 16:41:04 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void draw_player_view(t_data *game_data)
{
    int i;
    double cp_x = game_data->x2;
    double cp_y = game_data->y2;
    double radius = 720.0;

    i = 1;
    while (i < 72)
    {
        double temp_cp_x = cp_x;
        double temp_cp_y = cp_y;
        cp_x = temp_cp_x * cos(game_data->angle) - temp_cp_y * sin(game_data->angle);
        cp_y = temp_cp_x * sin(game_data->angle) + temp_cp_y * cos(game_data->angle);
        cp_x = (cp_x / sqrt(cp_x * cp_x + cp_y * cp_y)) * radius;
        cp_y = (cp_y / sqrt(cp_x * cp_x + cp_y * cp_y)) * radius;
        if (i > 2)
            draw_vertical_line(game_data,draw_line(game_data, game_data->pos_x, game_data->pos_y, game_data->pos_x + cp_x, game_data->pos_y + cp_y, 0xFF2D00),i);
        i++;
    }
}

void ft_put_windows(t_data *game_data)
{
    //initilisation des données
    game_data->angle = 1 * M_PI / 180.0;
    game_data->copy_angle = 1 * 90/3 * M_PI / 180.0;
    game_data->pos_x = 5;
    game_data->pos_y = 5;
    game_data->x2 = game_data->pos_x + 720;
    game_data->y2 = game_data->pos_y;
    
    //init de la fenetre
    game_data->mlx = mlx_init();
    game_data->win2 = mlx_new_window(game_data->mlx,720,480,"Cube3D");
    game_data->gi = mlx_new_image(game_data->mlx,720,480);
    game_data->addr = mlx_get_data_addr(game_data->gi,&game_data->bpp,&game_data->sl,&game_data->endian);
    mlx_key_hook(game_data->win2, ft_key, game_data);
    mlx_hook(game_data->win2, 17, 1l << 0, exit_game, game_data);
    mlx_loop(game_data->mlx);
}