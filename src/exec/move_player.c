/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:32:23 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/31 13:33:07 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	move_forward(t_data *param)
{
	param->player.pos_y -= SPEED * sin(param->player.angle);
	param->player.pos_x -= SPEED * cos(param->player.angle);
	show_minimap(param);
	return (0);
}

int	move_backward(t_data *param)
{
	param->player.pos_y += SPEED * sin(param->player.angle);
	param->player.pos_x += SPEED * cos(param->player.angle);
	show_minimap(param);
	return (0);
}

int	move_left(t_data *param)
{
	param->player.pos_y += SPEED * sin(param->player.angle + M_PI_2);
	param->player.pos_x += SPEED * cos(param->player.angle + M_PI_2);
	show_minimap(param);
	return (0);
}

int	move_right(t_data *param)
{
	param->player.pos_y -= SPEED * sin(param->player.angle + M_PI_2);
	param->player.pos_x -= SPEED * cos(param->player.angle + M_PI_2);
	show_minimap(param);
	return (0);
}
