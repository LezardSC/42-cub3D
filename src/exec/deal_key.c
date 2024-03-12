/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:17:18 by jrenault          #+#    #+#             */
/*   Updated: 2024/03/12 16:46:12 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	rotate_left(t_data *param)
{
	param->player.angle -= ROTATION_SPEED;
	show_minimap(param);
	return (0);
}

static int	rotate_right(t_data *param)
{
	param->player.angle += ROTATION_SPEED;
	show_minimap(param);
	return (0);
}

int	move_player(t_data *param)
{
	if (param->player.forward == TRUE)
		move_forward(param);
	if (param->player.backward == TRUE)
		move_backward(param);
	if (param->player.rotate_left == TRUE)
		rotate_left(param);
	if (param->player.rotate_right == TRUE)
		rotate_right(param);
	draw_floor(param);
	return (0);
}

int	key_release(int key, t_data *param)
{
	if (key == UP)
		param->player.forward = FALSE;
	if (key == DOWN)
		param->player.backward = FALSE;
	if (key == ROTATE_LEFT)
		param->player.rotate_left = FALSE;
	if (key == ROTATE_RIGHT)
		param->player.rotate_right = FALSE;
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
	if (key == ROTATE_LEFT)
		param->player.rotate_left = TRUE;
	if (key == ROTATE_RIGHT)
		param->player.rotate_right = TRUE;
	return (0);
}
