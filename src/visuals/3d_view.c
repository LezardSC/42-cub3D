/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:22:01 by tmalidi           #+#    #+#             */
/*   Updated: 2024/02/21 15:04:18 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"
#include <stdio.h>

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

void ft_put_3dview(t_data *game_data)
{
    // Initialisation des données du jeu
    
    int bpp = 0;
    int sl = 0;
    int endian = 0;
    int cube = 72;
    
    game_data->mlx = mlx_init();
    game_data->win = mlx_new_window(game_data->mlx, 720, 720, "Cube3D");

    // Chargement de l'image .xpm originale
    void *wall = mlx_xpm_file_to_image(game_data->mlx, "textures/wall_0.xpm", &cube, &cube);
    char *wall_data = mlx_get_data_addr(wall, &bpp, &sl, &endian);

    void *final = new_display(game_data,wall_data,300,300);
    
    // Affichage de l'image agrandie dans la fenêtre
    mlx_put_image_to_window(game_data->mlx, game_data->win, final, 0, 0);

    // Gestion de l'événement de fermeture de la fenêtre
    mlx_hook(game_data->win, 17, 1L << 0, exit_game, game_data);

    // Boucle principale
    mlx_loop(game_data->mlx);
}