/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:17:18 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/30 18:51:44 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	move_forward(t_data *param)
{
//	param->player.pos_y += SPEED *((param->player.x_2 * sin(param->player.copy_angle) + param->player.y_2 * cos(param->player.copy_angle)) / 4);
//    param->player.pos_x += SPEED * ((param->player.x_2 * cos(param->player.copy_angle) - param->player.y_2 * sin(param->player.copy_angle)) / 4);
	param->player.pos_y -= SPEED * sin(param->player.angle);
	param->player.pos_x -= SPEED * cos(param->player.angle);
	show_minimap(param);
	return (0);
}

static int	move_backward(t_data *param)
{
	param->player.pos_y += SPEED * sin(param->player.angle);
	param->player.pos_x += SPEED * cos(param->player.angle);
//	param->player.pos_y -= SPEED *((param->player.x_2 * sin(param->player.copy_angle) + param->player.y_2 * cos(param->player.copy_angle)) / 4);
  //  param->player.pos_x -= SPEED * ((param->player.x_2 * cos(param->player.copy_angle) - param->player.y_2 * sin(param->player.copy_angle)) / 4);
	show_minimap(param);
	return (0);
}

static int	move_left(t_data *param)
{
	param->player.pos_y += SPEED * sin(param->player.angle + M_PI_2);
	param->player.pos_x += SPEED * cos(param->player.angle + M_PI_2);
//	param->player.pos_y -= SPEED *((param->player.x_2 * sin(param->player.copy_angle) + param->player.y_2 * cos(param->player.copy_angle)) / 4);
  //  param->player.pos_x += SPEED * ((param->player.x_2 * cos(param->player.copy_angle) - param->player.y_2 * sin(param->player.copy_angle)) / 4);
	show_minimap(param);
	return (0);
}

static int	move_right(t_data *param)
{
	param->player.pos_y -= SPEED * sin(param->player.angle + M_PI_2);
	param->player.pos_x -= SPEED * cos(param->player.angle + M_PI_2);
//	param->player.pos_y += SPEED *((param->player.x_2 * sin(param->player.copy_angle) + param->player.y_2 * cos(param->player.copy_angle)) / 4);
//    param->player.pos_x -= SPEED * ((param->player.x_2 * cos(param->player.copy_angle) - param->player.y_2 * sin(param->player.copy_angle)) / 4);
	show_minimap(param);
	return (0);
}

static int	rotate_left(t_data *param)
{
	param->player.angle -= ROTATION_SPEED;
//	param->player.x_2 = ROTATION_SPEED * (param->player.x_2 * cos(param->player.angle) - param->player.y_2 * sin(param->player.angle));
//	param->player.y_2 = ROTATION_SPEED * (param->player.x_2 * sin(param->player.angle) + param->player.y_2 * cos(param->player.angle));
	show_minimap(param);
	return (0);
}

static int	rotate_right(t_data *param)
{
	param->player.angle += ROTATION_SPEED;
//	param->player.x_2 = ROTATION_SPEED * (param->player.x_2 * cos(param->player.angle) - param->player.y_2 * sin(param->player.angle));
//	param->player.y_2 = ROTATION_SPEED * (-(param->player.x_2) * sin(param->player.angle) + param->player.y_2 * cos(param->player.angle));
	show_minimap(param);
	return (0);
}

int	move_player(t_data *param)
{
	if (param->player.forward == TRUE)
		move_forward(param);
	else if (param->player.backward == TRUE)
		move_backward(param);
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
	ft_printf("key: %d\n", key);
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
	if (key == ROTATE_LEFT)
		rotate_left(param);
	if (key == ROTATE_RIGHT)
		rotate_right(param);
	return (0);
}
