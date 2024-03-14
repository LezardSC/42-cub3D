/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:43:07 by tmalidi           #+#    #+#             */
/*   Updated: 2024/03/14 16:43:27 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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