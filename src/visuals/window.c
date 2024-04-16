/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:28:46 by tmalidi           #+#    #+#             */
/*   Updated: 2024/04/10 09:57:18 by tmalidi          ###   ########.fr       */
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
	while (i < WINDOW_WIDTH)
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

	case_width = (double)TEX_SIDE;
	case_height = (double)TEX_SIDE;
	column_index = (x / case_width);
	line_index = (y / case_height);
	if (column_index >= gd->max_x)
		column_index = gd->max_x;
	if (column_index < 0)
		column_index = 0;
	if (line_index >= gd->max_y)
		line_index = gd->max_y;
	if (line_index < 0)
		line_index = 0;
	if (gd->map[line_index][column_index]
		&& gd->map[line_index][column_index] == '1')
		return (0);
	return (1);
}

void	init_tex(t_data *gd)
{
	if (north_tex(gd) && east_tex(gd) && south_tex(gd) && west_tex(gd))
		ft_key(0, gd);
	else
	{
		destroy_img(gd);
		free_all_param(gd);
		mlx_destroy_window(gd->mlx, gd->win);
		mlx_destroy_image(gd->mlx, gd->pixel.img);
		mlx_destroy_display(gd->mlx);
		free(gd->mlx);
		close(gd->fd);
		ft_printf("Error\nError in texture.\n");
		exit(0);
	}
}

void	init_pos(t_data *gd)
{
	double	angle;
	int		tmp;
	int		i;

	angle = 0;
	i = 0;
	if (gd->card == 'N')
		angle = 273;
	else if (gd->card == 'W')
		angle = 162;
	else if (gd->card == 'E')
		angle = 88;
	while (i < angle && angle != 0)
	{
		tmp = gd->x2;
		//gd->copy_angle += 0.000000001 * M_PI / 180;
		gd->x2 = gd->x2 * cos(gd->copy_angle * 35 * M_PI / 180.0 / 3)
			- gd->y2 * sin(gd->copy_angle * 35 * M_PI / 180.0 / 3);
		gd->y2 = tmp * sin(gd->copy_angle * 35 * M_PI / 180.0 / 3)
			+ gd->y2 * cos(gd->copy_angle * 35 * M_PI / 180.0 / 3);
		i++;
	}
}

void	ft_put_windows(t_data *gd)
{
	gd->tex_side = TEX_SIDE;
	gd->angle = ((double)70 / (double)WINDOW_WIDTH) * M_PI / 180.0;
	gd->copy_angle = 35 * M_PI / 180.0;
	gd->x2 = gd->pos_y + WINDOW_WIDTH * cos(gd->copy_angle);
	gd->y2 = gd->pos_x + WINDOW_WIDTH * sin(gd->copy_angle);
	init_pos(gd);
	init_tex(gd);
	mlx_hook(gd->win, 02, 1L << 0, deal_key, gd);
	mlx_hook(gd->win, 17, 0, close_win, gd);
	mlx_key_hook(gd->win, key_release, gd);
	mlx_loop_hook(gd->mlx, move_player, gd);
	mlx_loop(gd->mlx);
}
