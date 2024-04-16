/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:09:29 by jrenault          #+#    #+#             */
/*   Updated: 2024/03/21 10:13:39 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	init_map(t_data *param, int i)
{
	param->floor_color = malloc(sizeof(int) * 3);
	if (!param->floor_color)
		return (1);
	param->sky_color = malloc(sizeof(int) * 3);
	if (!param->sky_color)
		return (1);
	i = 3;
	while (--i >= 0)
	{
		param->floor_color[i] = 0;
		param->sky_color[i] = 0;
	}
	param->textures = malloc(sizeof(int) * 6);
	if (!param->textures)
		return (1);
	i = 6;
	while (--i >= 0)
		param->textures[i] = 0;
	param->map_textures = malloc(sizeof(char *) * (4 + 1));
	if (!param->map_textures)
		return (1);
	i = 4;
	while (--i >= 0)
		param->map_textures[i] = NULL;
	return (0);
}

static void	init_player(t_data *param)
{
	param->player.pos_x = 0;
	param->player.pos_y = 0;
	param->player.forward = FALSE;
	param->player.backward = FALSE;
	param->player.rotate_left = FALSE;
	param->player.rotate_right = FALSE;
	if (param->direction == 'N')
		param->player.angle = 90 * M_PI / 180.0;
	else if (param->direction == 'S')
		param->player.angle = 270 * M_PI / 180.0;
	else if (param->direction == 'E')
		param->player.angle = 0 * M_PI / 180.0;
	else if (param->direction == 'W')
		param->player.angle = 180 * M_PI / 180.0;
}

static int	init_textures(t_data *param)
{
	param->gi_n = mlx_xpm_file_to_image
	(param->mlx, param->map_textures[NO], &param->tex_side, &param->tex_side);
	if (!param->gi_n)
		return (1);
	param->gi_s = mlx_xpm_file_to_image
	(param->mlx, param->map_textures[SO], &param->tex_side, &param->tex_side);
	if (!param->gi_s)
		return (1);
	param->gi_w = mlx_xpm_file_to_image
	(param->mlx, param->map_textures[WE], &param->tex_side, &param->tex_side);
	if (!param->gi_w)
		return (1);
	param->gi_e = mlx_xpm_file_to_image
	(param->mlx, param->map_textures[EA], &param->tex_side, &param->tex_side);
	if (!param->gi_e)
		return (1);
	return (0);
}

int	init_pixels(t_data *param)
{
	if (param->max_x > param->max_y)
		param->pixel.size = ((double)MINIMAP_WIDTH / (param->max_x + 1));
	else
		param->pixel.size = ((double)MINIMAP_HEIGHT / (param->max_y + 1));
	param->pixel.radius = param->pixel.size / 2;
	if (init_textures(param) == 1)
		return (ft_printf("Error\ntexture can't be load.\n"), 1);
	init_player(param);
	return (0);
}


int	init_param(t_data *param)
{
	if (init_map(param, 3) == 1)
		return (1);
	param->check_colors = malloc(sizeof(int) * 2);
	if (!param->check_colors)
		return (1);
	param->check_colors[F] = 0;
	param->check_colors[C] = 0;
	param->map = NULL;
	return (0);
}
