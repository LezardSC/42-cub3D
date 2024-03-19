/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:43:07 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/19 18:27:05 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//inutile pour l'instant

/*void *new_display(t_data *game_data, char *wall_data,int width, int height)
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
}*/

char *new_display(t_data *game_data, char *wall_data, int width, int height, int ray)
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
	// Pour n'afficher qu'une colonne, nous utilisons seulement la première colonne
	int original_x = ray % 72; // Utilisation de la première colonne uniquement

	for (int y = 0; y < height; y++) {
		// Calcul des indices dans l'image originale
		int original_y = y * original_height / height;
		int original_index = original_y * original_width * (bpp / 8) + original_x * (bpp / 8);

		// Calcul de l'indice dans l'image agrandie
		int enlarged_index = y * sl;

		// Copie des données de l'image originale vers l'image agrandie
		for (int i = 0; i < bpp / 8; i++) {
			if (original_index + i < original_width * original_height * (bpp / 8) && enlarged_index + i < width * height * (bpp / 8))
				enlarged_wall_data[enlarged_index + i] = wall_data[original_index + i];
		}
	}
	return (enlarged_wall);
}

/*
void *new_display(t_data *game_data, char *wall_data, int width, int height, int *column_widths, int num_columns) {
	int bpp = 0;
	int sl = 0;
	int endian = 0;
	int original_width = 72;
	int original_height = 72;

	void *enlarged_wall = mlx_new_image(game_data->mlx, width, height);
	char *enlarged_wall_data = mlx_get_data_addr(enlarged_wall, &bpp, &sl, &endian);

	int current_x = 0; // Position horizontale actuelle dans l'image agrandie

	for (int col = 0; col < num_columns; col++) {
		int column_width = column_widths[col];
		for (int x = 0; x < column_width; x++) {
			for (int y = 0; y < height; y++) {
				// Calcule les coordonnées correspondantes dans l'image originale
				int original_x = (current_x + x) * original_width / width;
				int original_y = y * original_height / height;

				// Calcule les indices dans les données de l'image originale et agrandie
				int original_index = original_y * original_width * (bpp / 8) + original_x * (bpp / 8);
				int enlarged_index = y * sl + (current_x + x) * (bpp / 8);

				// Copie les données de l'image originale vers l'image agrandie
				for (int i = 0; i < bpp / 8; i++) {
					if (original_index + i < original_width * original_height * (bpp / 8) && 
						enlarged_index + i < width * height * (bpp / 8)) {
						enlarged_wall_data[enlarged_index + i] = wall_data[original_index + i];
					}
				}
			}
		}
		current_x += column_width; // Met à jour la position horizontale actuelle
	}

	return enlarged_wall;
}*/

/*void	put_image_in_image(t_data *game_data, int x,int y, char *img_data)
{
	int i;
	int j;
	int dest_x;
	int dest_y;
	int	source_index;
	int dest_index;
	int c;

	i = 0;
	printf("oui\n");
	while (i < 72)
	{
		j = 0;
		while (j < 72)
		{
			dest_y = y + i;
			dest_x = x + j;
			if (dest_x >= 0 && dest_x < WINDOW_WIDTH && dest_y >= 0 && dest_y < WINDOW_HEIGHT)
			{
				c = 0;
				dest_index = dest_y * game_data->pixel.line_length + dest_x * (game_data->pixel.bits_per_pixel / 8);

				source_index = (i * 72 + j) * (game_data->pixel.bits_per_pixel / 8) + i * (game_data->pixel.bits_per_pixel / 8);
				
				while (c < game_data->pixel.bits_per_pixel / 8)
				{
					game_data->gi_data[dest_index + c] = img_data[source_index + c];
					c++;
				}
			}
			j++;
		}
		i++;
	}
}*/

/*void	 ft_put_height(t_data *gd, int x,int y, int img_height)
{
	int i;
	int pixel;

	i = 0;
	while (i < img_height)
	{
		pixel = get_pixel_color(gd,x,i);
		put_pixel_to_image(gd,x,y,pixel);
		i++;
	}
}*/