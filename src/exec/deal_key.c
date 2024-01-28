/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:17:18 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/28 07:44:33 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	move_up(t_data *param)
{
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_image(param->mlx, param->pixel.img);
	param->player.pos_y -= SPEED;
	show_minimap(param);
	return (0);
}

static int	move_left(t_data *param)
{
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_image(param->mlx, param->pixel.img);
	param->player.pos_x -= SPEED;
	show_minimap(param);
	return (0);
}

static int	move_down(t_data *param)
{
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_image(param->mlx, param->pixel.img);
	param->player.pos_y += SPEED;
	show_minimap(param);
	return (0);
}

static int	move_right(t_data *param)
{
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_image(param->mlx, param->pixel.img);
	param->player.pos_x += SPEED;
	show_minimap(param);
	return (0);
}

int	move_player(t_data *param)
{
	if (param->player.forward == TRUE)
		move_up(param);
	else if (param->player.backward == TRUE)
		move_down(param);
	else if (param->player.left == TRUE)
		move_left(param);
	else if (param->player.right == TRUE)
		move_right(param);
	return (0);
}

int	key_release(int key, t_data *param)
{
	if (key == UP)
		param->player.forward = FALSE;
	if (key == DOWN)
		param->player.backward = FALSE;
	if (key == LEFT)
		param->player.left = FALSE;
	if (key == RIGHT)
		param->player.right = FALSE;
	return (0);
}

int	deal_key(int key, t_data *param)
{
	if (key == ESC)
		close_win(param);
	if (key == UP)
		param->player.forward = TRUE;
	if (key == DOWN)
		param->player.backward = TRUE;
	if (key == LEFT)
		param->player.left = TRUE;
	if (key == RIGHT)
		param->player.right = TRUE;
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
