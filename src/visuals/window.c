/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:28:46 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/20 17:17:54 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	draw_player_view(t_data *game_data)
{
	int		i;
	t_pview	view;

	i = 0;
	view.radius = WINDOW_WIDTH;
	view.cp_y = game_data->y2;
	view.cp_x = game_data->x2;
	while (i < 1920)
	{
		view.temp_cp_x = view.cp_x;
		view.temp_cp_y = view.cp_y;
		view.cp_x = view.temp_cp_x * cos(game_data->angle)
			- view.temp_cp_y * sin(game_data->angle);
		view.cp_y = view.temp_cp_x * sin(game_data->angle)
			+ view.temp_cp_y * cos(game_data->angle);
		view.cp_x = (view.cp_x / sqrt(view.cp_x * view.cp_x
					+ view.cp_y * view.cp_y)) * view.radius;
		view.cp_y = (view.cp_y / sqrt(view.cp_x * view.cp_x
					+ view.cp_y * view.cp_y)) * view.radius;
		draw_vertical_line(game_data, draw_line(game_data, game_data->pos_x
				+ view.cp_x, game_data->pos_y + view.cp_y), i);
		i++;
	}
}

int	collision(t_data *gd, int x, int y)
{
	float	case_height;
	float	case_width;
	int		column_index;
	int		line_index;

	case_width = WINDOW_WIDTH / gd->max_x;
	case_height = WINDOW_HEIGHT / gd->max_y;
	column_index = (int)(x / case_width);
	line_index = (int)(y / case_height);
	if (gd->map[line_index][column_index] == '1')
		return (0);
	return (1);
}

void	ft_put_windows(t_data *game_data)
{
	int	side;
	int	i;

	side = 72;
	game_data->angle = 0.036458333 * M_PI / 180.0;
	game_data->copy_angle = 34 * M_PI / 180.0;
	game_data->x2 = game_data->pos_x - WINDOW_WIDTH;
	game_data->y2 = game_data->pos_y;
	game_data->gi = mlx_xpm_file_to_image
		(game_data->mlx, "textures/wall_north.xpm", &side, &side);
	game_data->gi_data = mlx_get_data_addr
		(game_data->gi, &game_data->bpp, &game_data->sl, &game_data->endian);
	i = 0;
	while (i < 72)
	{
		game_data->tex.img = new_display
			(game_data, game_data->gi_data, 1, WINDOW_HEIGHT, i);
		game_data->tex.addr[i] = mlx_get_data_addr(game_data->tex.img,
				&game_data->tex.bits_per_pixel,
				&game_data->tex.line_length, &game_data->tex.endian);
		i++;
	}
	mlx_hook(game_data->win, 02, 1L << 0, deal_key, game_data);
	mlx_hook(game_data->win, 17, 0, close_win, game_data);
	mlx_key_hook(game_data->win, key_release, game_data);
	mlx_loop_hook(game_data->mlx, move_player, game_data);
	mlx_loop(game_data->mlx);
}
