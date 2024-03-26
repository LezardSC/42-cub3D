/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   card.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:41:33 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/22 14:02:14 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void north_tex(t_data *gd)
{
    int i;
    
    gd->gi = mlx_xpm_file_to_image
		(gd->mlx, "textures/wall_north.xpm", &gd->tex_side, &gd->tex_side);
	gd->gi_data = mlx_get_data_addr
		(gd->gi, &gd->bpp, &gd->sl, &gd->endian);
	i = 0;
	while (i < TEX_SIDE)
	{
		gd->tex_north.img = new_display
			(gd, gd->gi_data, i);
		gd->tex_north.addr[i++] = mlx_get_data_addr(gd->tex_north.img,
				&gd->tex_north.bits_per_pixel,
				&gd->tex_north.line_length, &gd->tex_north.endian);
	}
}

void south_tex(t_data *gd)
{
    int i;
    
    gd->gi = mlx_xpm_file_to_image
		(gd->mlx, "textures/wall_south.xpm", &gd->tex_side, &gd->tex_side);
	gd->gi_data = mlx_get_data_addr
		(gd->gi, &gd->bpp, &gd->sl, &gd->endian);
	i = 0;
	while (i < TEX_SIDE)
	{
		gd->tex_south.img = new_display
			(gd, gd->gi_data, i);
		gd->tex_south.addr[i++] = mlx_get_data_addr(gd->tex_south.img,
				&gd->tex_south.bits_per_pixel,
				&gd->tex_south.line_length, &gd->tex_south.endian);
	}
}

void west_tex(t_data *gd)
{
    int i;
    
    gd->gi = mlx_xpm_file_to_image
		(gd->mlx, "textures/wall_west.xpm", &gd->tex_side, &gd->tex_side);
	gd->gi_data = mlx_get_data_addr
		(gd->gi, &gd->bpp, &gd->sl, &gd->endian);
	i = 0;
	while (i < TEX_SIDE)
	{
		gd->tex_west.img = new_display
			(gd, gd->gi_data, i);
		gd->tex_west.addr[i++] = mlx_get_data_addr(gd->tex_west.img,
				&gd->tex_west.bits_per_pixel,
				&gd->tex_west.line_length, &gd->tex_west.endian);
	}
}

void east_tex(t_data *gd)
{
    int i;
    
    gd->gi = mlx_xpm_file_to_image
		(gd->mlx, "textures/wall_east.xpm", &gd->tex_side, &gd->tex_side);
	gd->gi_data = mlx_get_data_addr
		(gd->gi, &gd->bpp, &gd->sl, &gd->endian);
	i = 0;
	while (i < TEX_SIDE)
	{
		gd->tex_east.img = new_display
			(gd, gd->gi_data, i);
		gd->tex_east.addr[i++] = mlx_get_data_addr(gd->tex_east.img,
				&gd->tex_east.bits_per_pixel,
				&gd->tex_east.line_length, &gd->tex_east.endian);
	}
}

