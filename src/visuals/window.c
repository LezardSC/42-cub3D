/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:28:46 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/21 14:04:40 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	draw_player_view(t_data *gd)
{
	int		i;
	t_pview	view;
	t_ray_data ray;

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
		ray = draw_line(gd, gd->pos_x
				+ view.cp_x, gd->pos_y + view.cp_y, i);
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

void	x_wall(t_data *gd)
{
	int x;
	int	y;
	int	c;
	
	c = 0;
	y = 0;
	//printf("x == %d\n", x);
	while (y < gd->max_y)
	{
		x = 0;
		while (x < gd->max_x)
		{
			if ((((x + 1 < gd->max_x) && (x - 1 > 0)) && ((gd->map[y][x] == '1' && gd->map[y][x - 1] == '0') || (gd->map[y][x] == '1' && gd->map[y][x + 1] == '0'))) || x == 0 || x == gd->max_x - 1)
			//if (gd->map[y][x] == '1')
			{
				gd->x_wall[c] = x;
				c++;
			}
			x++;
		}
		y++;
	}
}

int is_x_wall(int x, t_data *gd)
{
	int i;

	i = 0;
	while (i < gd->max_x)
	{
		if (gd->x_wall[i] == x*gd->max_x / 1920)
			return (1);
		//printf("%d | %d\n", gd->x_wall[i], x*gd->max_x / 1920);
		i++;
	}
	return (0);
}

void	ft_put_windows(t_data *gd)
{
	int	i;

	gd->tex_side = 72;
	gd->x_wall = malloc(sizeof(int) * (gd->max_x * gd->max_y));
	x_wall(gd);
	gd->angle = 0.036458333 * M_PI / 180.0;
	gd->copy_angle = 34 * M_PI / 180.0;
	gd->x2 = gd->pos_x + WINDOW_WIDTH * gd->angle;
	gd->y2 = gd->pos_y;
	gd->gi = mlx_xpm_file_to_image
		(gd->mlx, "textures/wall_north.xpm", &gd->tex_side, &gd->tex_side);
	gd->gi_data = mlx_get_data_addr
		(gd->gi, &gd->bpp, &gd->sl, &gd->endian);
	i = 0;
	while (i < 72)
	{
		gd->tex.img = new_display
			(gd, gd->gi_data, i);
		gd->tex.addr[i++] = mlx_get_data_addr(gd->tex.img,
				&gd->tex.bits_per_pixel,
				&gd->tex.line_length, &gd->tex.endian);
	}
	mlx_hook(gd->win, 02, 1L << 0, deal_key, gd);
	mlx_hook(gd->win, 17, 0, close_win, gd);
	mlx_key_hook(gd->win, key_release, gd);
	mlx_loop_hook(gd->mlx, move_player, gd);
	mlx_loop(gd->mlx);
}
