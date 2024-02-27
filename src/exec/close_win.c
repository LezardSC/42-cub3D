/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:15:53 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/27 03:50:49 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	close_win(t_data *param)
{
	mlx_destroy_window(param->mlx, param->win);
	free_all_param(param);
	mlx_destroy_image(param->mlx, param->drawmm.img);
	mlx_destroy_image(param->mlx, param->drawmap.img);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	close(param->fd);
	exit (0);
}
