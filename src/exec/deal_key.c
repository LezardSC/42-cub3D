/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:17:18 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/27 03:53:00 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	move_up(t_data *param)
{
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_image(param->mlx, param->pixel.img);
	param->pos_y--;
	show_minimap(param);
	return (0);
}

static int	move_left(t_data *param)
{
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_image(param->mlx, param->pixel.img);
	param->pos_x--;
	show_minimap(param);
	return (0);
}

static int	move_down(t_data *param)
{
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_image(param->mlx, param->pixel.img);
	param->pos_y++;
	show_minimap(param);
	return (0);
}

static int	move_right(t_data *param)
{
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_image(param->mlx, param->pixel.img);
	param->pos_x++;
	show_minimap(param);
	return (0);
}

int	deal_key(int key, t_data *param)
{
	ft_printf("key: %d\n", key);
	if (key == 65307)
		close_win(param);
	if (key == 119)
		move_up(param);
	if (key == 97)
		move_left(param);
	if (key == 115)
		move_down(param);
	if (key == 100)
		move_right(param);
	// if (key == 105)
	// 	rotate_up(param);
	// if (key == 106)
	// 	rotate_left(param);
	// if (key == 107)
	// 	rotate_down(param);
	// if (key == 108)
	// 	rotate_right(param);
	return (0);
}
