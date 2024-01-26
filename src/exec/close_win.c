/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:15:53 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/26 22:16:34 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	close_win(t_data *param)
{
	mlx_destroy_window(param->mlx, param->win);
	free_all_param(param);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	exit (0);
}
