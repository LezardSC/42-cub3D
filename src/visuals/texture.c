/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:43:07 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/20 16:17:20 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *new_display(t_data *game_data, char *wall_data, int width, int height, int ray)
{
	int bpp = 0;
	int sl = 0;
	int endian = 0;
	int original_width = 72;
	int original_height = 72;

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
