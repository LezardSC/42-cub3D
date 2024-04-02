/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:28:46 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/25 14:17:59 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	draw_player_view(t_data *gd)
{
	int			i;
	t_pview		view;
	t_ray_data	ray;

	i = 0;
	view.radius = WINDOW_WIDTH;
	view.cp_y = gd->y2;
	view.cp_x = gd->x2;
	while (i < 1920)
	{
		view.temp_cp_x = view.cp_x;
		view.temp_cp_y = view.cp_y;
		view.cp_x = view.temp_cp_x * cos(gd->angle)
			- view.temp_cp_y * sin(gd->angle);
		view.cp_y = view.temp_cp_x * sin(gd->angle)
			+ view.temp_cp_y * cos(gd->angle);
		view.cp_x = (view.cp_x / sqrt(view.cp_x * view.cp_x
					+ view.cp_y * view.cp_y)) * view.radius;
		view.cp_y = (view.cp_y / sqrt(view.cp_x * view.cp_x
					+ view.cp_y * view.cp_y)) * view.radius;
		ray = draw_line(gd, gd->pos_x + view.cp_x, gd->pos_y + view.cp_y, i);
		draw_vertical_line(gd, &ray);
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

void	init_tex(t_data *gd)
{
	north_tex(gd);
	east_tex(gd);
	south_tex(gd);
	west_tex(gd);
	ft_key(0, gd);
}

/*void init_pos(t_data *gd)
{
	if (gd->card == 'N')
	{
		gd->x2 = gd->pos_x;
		gd->y2 = gd->pos_y - 1920;
	}
	if (gd->card == 'S')
	{
		gd->x2 = gd->pos_x;
		gd->y2 = gd->pos_y + 1920;
	}
	if (gd->card == 'W')
	{
		gd->x2 = gd->pos_x - 1920;
		gd->y2 = gd->pos_y;
	}
	if (gd->card == 'E')
	{
		gd->x2 = gd->pos_x + 1920;
		gd->y2 = gd->pos_y;
	}
}*/

/*void	init_pos(t_data *gd)
{
	double	angle;

	angle = 180 * M_PI / 180.0;
	if (gd->card == 'N')
	{
		gd->x2 = gd->pos_x;
		gd->y2 = gd->pos_y - 1920 * cos(angle);
	}
	else if (gd->card == 'S')
	{
		gd->x2 = gd->pos_x;
		gd->y2 = gd->pos_y + 1920 * cos(angle);
	}
	else if (gd->card == 'W')
	{
		gd->x2 = gd->pos_x - 1920 * sin(angle);
		gd->y2 = gd->pos_y;
	}
	else if (gd->card == 'E')
	{
		gd->x2 = gd->pos_x - 1920 * cos(gd->copy_angle + angle);
		gd->y2 = gd->pos_y - 1920 * sin(gd->copy_angle + angle);
	}
}*/

void	ft_put_windows(t_data *gd)
{
	gd->tex_side = TEX_SIDE;
	gd->angle = 0.036458333 * M_PI / 180.0;
	gd->copy_angle = 35 * M_PI / 180.0;
	gd->x2 = gd->pos_y + 1920 * cos(gd->copy_angle + 270 * M_PI / 180);
	gd->y2 = gd->pos_x + 1920 * sin(gd->copy_angle + 270 * M_PI / 180);
	//init_pos(gd);
	init_tex(gd);
	mlx_hook(gd->win, 02, 1L << 0, deal_key, gd);
	mlx_hook(gd->win, 17, 0, close_win, gd);
	mlx_key_hook(gd->win, key_release, gd);
	mlx_loop_hook(gd->mlx, move_player, gd);
	mlx_loop(gd->mlx);
}
