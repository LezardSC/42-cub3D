/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:22:01 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/12 16:45:12 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include <stdio.h>

//inutile pour l'instant

void *new_display(t_data *game_data, char *wall_data,int width, int height)
{
	int bpp = 0;
	int sl = 0;
	int endian = 0;
	 // Dimensions de l'image originale
	int original_width = 72;
	int original_height = 72;

	// Création de la nouvelle image agrandie
	void *enlarged_wall = mlx_new_image(game_data->mlx, width, height);
	char *enlarged_wall_data = mlx_get_data_addr(enlarged_wall, &bpp, &sl, &endian);

	// Agrandissement de l'image
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			// Calcul des indices dans les images originale et agrandie
			int original_x = x * original_width / width;
			int original_y = y * original_height / height;

			int original_index = original_y * original_width * (bpp / 8) + original_x * (bpp / 8);
			int enlarged_index = y * sl + x * (bpp / 8);

			// Copie des données de l'image originale vers l'image agrandie
			for (int i = 0; i < bpp / 8; i++) {
				if (original_index + i < original_width * original_height * (bpp / 8) && enlarged_index + i < width * height * (bpp / 8))
					enlarged_wall_data[enlarged_index + i] = wall_data[original_index + i];
			}
		}
	}
	return enlarged_wall;
}

void	draw_floor(t_data *gd)
{
	int	i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		other_draw_line(gd, i, 0, i, WINDOW_HEIGHT / 2, BLUE_COLOR);
		other_draw_line(gd, i, WINDOW_HEIGHT / 2, i, WINDOW_HEIGHT, GREY_COLOR);
		i++;
	}
}

void	draw_vertical_line(t_data *game_data, float dist, int ray)
{
	float	height;
	float	y1;
	int		x;
	int		i;

	if (dist == -1)
		return ;
	height = (30 * WINDOW_HEIGHT) / dist;
	y1 = (WINDOW_HEIGHT / 2) - height / 2;
	x = (WINDOW_WIDTH / 73) * ray;
	i = 0;
	while (i < 30)
	{
		other_draw_line(game_data, x + i, y1, x + i, y1 + height, ORANGE_COLOR);
		i++;
	}
}

void	put_pixel_to_image(t_data *gd, int x, int y, int color)
{
	char	*dst;

	dst = gd->pixel.addr + (y * gd->pixel.line_length + x
			* (gd->pixel.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
