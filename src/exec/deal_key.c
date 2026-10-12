/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:17:18 by jrenault          #+#    #+#             */
/*   Updated: 2024/03/21 10:14:34 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

static void	apply_moves(t_data *param, double dt)
{
	double	forward;
	double	strafe;

	forward = param->player.forward - param->player.backward;
	strafe = param->player.right - param->player.left;
	if (forward != 0 && strafe != 0)
	{
		forward *= M_SQRT1_2;
		strafe *= M_SQRT1_2;
	}
	if (forward != 0)
		move_dir(param, 0, forward * MOVE_SPEED * dt);
	if (strafe != 0)
		move_dir(param, M_PI / 2, strafe * STRAFE_SPEED * dt);
	if (param->player.rotate_left)
		rotate_view(param, -ROT_SPEED * dt);
	if (param->player.rotate_right)
		rotate_view(param, ROT_SPEED * dt);
}

int	move_player(t_data *param)
{
	double	now;
	double	dt;

	now = get_time();
	dt = now - param->last_time;
	param->last_time = now;
	if (dt > MAX_FRAME_TIME)
		dt = MAX_FRAME_TIME;
	if (!param->player.forward && !param->player.backward
		&& !param->player.left && !param->player.right
		&& !param->player.rotate_left && !param->player.rotate_right)
		return (0);
	apply_moves(param, dt);
	ft_key(0, param);
	return (0);
}

int	key_release(int key, t_data *param)
{
	if (key == UP)
		param->player.forward = FALSE;
	if (key == DOWN)
		param->player.backward = FALSE;
	if (key == ROTATE_LEFT || key == ROTATE_LEFT2)
		param->player.rotate_left = FALSE;
	if (key == ROTATE_RIGHT || key == ROTATE_RIGHT2)
		param->player.rotate_right = FALSE;
	if (key == STRAFE_RIGHT)
		param->player.right = FALSE;
	if (key == STRAFE_LEFT)
		param->player.left = FALSE;
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
	if (key == ROTATE_LEFT || key == ROTATE_LEFT2)
		param->player.rotate_left = TRUE;
	if (key == ROTATE_RIGHT || key == ROTATE_RIGHT2)
		param->player.rotate_right = TRUE;
	if (key == STRAFE_RIGHT)
		param->player.right = TRUE;
	if (key == STRAFE_LEFT)
		param->player.left = TRUE;
	return (0);
}
