/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:32:23 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/31 21:38:27 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

/*
	each function to move check if there is collision, and move the player in the direction based on the rotation.
	the calcul is weird and I used GPT to help me to be honest, but it works well and that's the principal.

	check collision will just do what the name says. It's not perfect right now because it check with the center of the player,
	so the player could go half in the wall then glitch and pass through it. We will see that later.
*/

static int	check_collision(t_data *param, double new_y, double new_x)
{
	int	check_y;
	int	check_x;

	check_y = (new_y / param->pixel.size);
	check_x = (new_x / param->pixel.size);
	return (param->map[check_y][check_x] == '1');
}

int	move_forward(t_data *param)
{
	double	new_y;
	double	new_x;

	new_y = param->player.pos_y - SPEED * sin(param->player.angle);
	new_x = param->player.pos_x - SPEED * cos(param->player.angle);
	if (!check_collision(param, new_y, new_x))
	{
		param->player.pos_y = new_y;
		param->player.pos_x = new_x;
	}
	show_map(param);
	return (0);
}

int	move_backward(t_data *param)
{
	double	new_y;
	double	new_x;

	new_y = param->player.pos_y + SPEED * sin(param->player.angle);
	new_x = param->player.pos_x + SPEED * cos(param->player.angle);
	if (!check_collision(param, new_y, new_x))
	{
		param->player.pos_y = new_y;
		param->player.pos_x = new_x;
	}
	show_map(param);
	return (0);
}

int	move_left(t_data *param)
{
	double	new_y;
	double	new_x;

	new_y = param->player.pos_y + SPEED * sin(param->player.angle + M_PI_2);
	new_x = param->player.pos_x + SPEED * cos(param->player.angle + M_PI_2);
	if (!check_collision(param, new_y, new_x))
	{
		param->player.pos_y = new_y;
		param->player.pos_x = new_x;
	}
	show_map(param);
	return (0);
}

int	move_right(t_data *param)
{
	double	new_y;
	double	new_x;

	new_y = param->player.pos_y - SPEED * sin(param->player.angle + M_PI_2);
	new_x = param->player.pos_x - SPEED * cos(param->player.angle + M_PI_2);
	if (!check_collision(param, new_y, new_x))
	{
		param->player.pos_y = new_y;
		param->player.pos_x = new_x;
	}
	show_map(param);
	return (0);
}
