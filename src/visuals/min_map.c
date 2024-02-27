/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:45:31 by tmalidi           #+#    #+#             */
/*   Updated: 2024/02/26 18:46:51 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void draw_circle(t_data *game_data, int xc, int yc, int radius, int color)
{
    int x = radius;
    int y = 0;
    int radiusError = 1 - x;

    radiusError = 1 - x;
    while (x >= y)
    {
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
