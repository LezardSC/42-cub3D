/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:15:53 by jrenault          #+#    #+#             */
/*   Updated: 2024/04/10 09:58:56 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	destroy_gi(t_data *param)
{
	if (param->gi_n)
		mlx_destroy_image(param->mlx, param->gi_n);
	if (param->gi_s)
		mlx_destroy_image(param->mlx, param->gi_s);
	if (param->gi_w)
		mlx_destroy_image(param->mlx, param->gi_w);
	if (param->gi_e)
		mlx_destroy_image(param->mlx, param->gi_e);
}

void	destroy_img(t_data *param, int j)
{
	int	i;

	i = 0;
	while (i < TEX_SIDE)
	{
		if (j > 0)
			mlx_destroy_image(param->mlx, param->tex_north.img[i]);
		if (j > 1)
			mlx_destroy_image(param->mlx, param->tex_east.img[i]);
		if (j > 2)
			mlx_destroy_image(param->mlx, param->tex_south.img[i]);	
		if (j > 3)
			mlx_destroy_image(param->mlx, param->tex_west.img[i]);
		i++;
	}
	destroy_gi(param);
}

int	close_win(t_data *param)
{
	mlx_destroy_window(param->mlx, param->win);
	destroy_img(param, 4);
	free_all_param(param);
	mlx_destroy_image(param->mlx, param->pixel.img);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	close(param->fd);
	exit (0);
}
