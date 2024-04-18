/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   card.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:41:33 by tmalidi           #+#    #+#             */
/*   Updated: 2024/04/10 10:00:27 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	north_tex(t_data *gd)
{
	int	i;

	gd->gi_data = mlx_get_data_addr
		(gd->gi_n, &gd->bpp, &gd->sl, &gd->endian);
	i = 0;
	while (i < TEX_SIDE)
	{
		gd->tex_north.img[i] = mlx_new_image(gd->mlx, 1, WINDOW_WIDTH);
		new_display(gd, gd->gi_data, i, gd->tex_north.img[i]);
		gd->tex_north.addr[i] = mlx_get_data_addr(gd->tex_north.img[i],
				&gd->tex_north.bits_per_pixel,
				&gd->tex_north.line_length, &gd->tex_north.endian);
		i++;
	}
	return (1);
}

int	south_tex(t_data *gd)
{
	int	i;

	gd->gi_data = mlx_get_data_addr
		(gd->gi_s, &gd->bpp, &gd->sl, &gd->endian);
	i = 0;
	while (i < TEX_SIDE)
	{
		gd->tex_south.img[i] = mlx_new_image(gd->mlx, 1, WINDOW_WIDTH);
		new_display_mirror(gd, gd->gi_data, i, gd->tex_south.img[i]);
		gd->tex_south.addr[i] = mlx_get_data_addr(gd->tex_south.img[i],
				&gd->tex_south.bits_per_pixel,
				&gd->tex_south.line_length, &gd->tex_south.endian);
		i++;
	}
	return (1);
}

int	west_tex(t_data *gd)
{
	int	i;

	gd->gi_data = mlx_get_data_addr
		(gd->gi_w, &gd->bpp, &gd->sl, &gd->endian);
	i = 0;
	while (i < TEX_SIDE)
	{
		gd->tex_west.img[i] = mlx_new_image(gd->mlx, 1, WINDOW_WIDTH);
		new_display_mirror(gd, gd->gi_data, i, gd->tex_west.img[i]);
		gd->tex_west.addr[i] = mlx_get_data_addr(gd->tex_west.img[i],
				&gd->tex_west.bits_per_pixel,
				&gd->tex_west.line_length, &gd->tex_west.endian);
		i++;
	}
	return (1);
}

int	east_tex(t_data *gd)
{
	int	i;

	gd->gi_data = mlx_get_data_addr
		(gd->gi_e, &gd->bpp, &gd->sl, &gd->endian);
	i = 0;
	while (i < TEX_SIDE)
	{
		gd->tex_east.img[i] = mlx_new_image(gd->mlx, 1, WINDOW_WIDTH);
		new_display(gd, gd->gi_data, i, gd->tex_east.img[i]);
		gd->tex_east.addr[i] = mlx_get_data_addr(gd->tex_east.img[i],
				&gd->tex_east.bits_per_pixel,
				&gd->tex_east.line_length, &gd->tex_east.endian);
		i++;
	}
	return (1);
}
