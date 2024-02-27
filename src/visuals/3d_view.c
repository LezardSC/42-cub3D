/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:22:01 by tmalidi           #+#    #+#             */
/*   Updated: 2024/02/26 18:27:53 by tmalidi          ###   ########.fr       */
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

void draw_floor(t_data *gd)
{
    int i;
    
    i = 0;
    while (i < 720)
    {
        other_draw_line(gd,i,0,i,480/2,0x0100FF);
        other_draw_line(gd,i,480/2,i,480,0x646464);
        i++;
    }
}

void draw_vertical_line(t_data *game_data, float dist, int ray)
{
    if (dist == -1)
        return;
    float height;

    height = (20*480) / dist;
    float y1 = (480/2) - height/2;
    int x = (720/70)*ray;
    int i = 0;
    while (i < 10)
    {
        other_draw_line(game_data,x+i,y1,x+i,y1+height,0xFF2D00);
        i++;
    }
}

void put_pixel_to_image(t_data *gd, int x, int y, int color)
{
    char *dst = gd->addr + (y * gd->sl + x * (gd->bpp / 8));

    // La couleur est représentée en format BGR (bleu, vert, rouge) sur 32 bits
    *(unsigned int *)dst = color;
}

/*void ft_put_3dview(t_data *game_data)
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
    void *side = new_display(game_data,wall_data,50,300);
    
    // Affichage de l'image agrandie dans la fenêtre
    mlx_put_image_to_window(game_data->mlx, game_data->win, final, 720/2 - 300/2, 100);
    mlx_put_image_to_window(game_data->mlx, game_data->win, side, 50, 100);

    // Gestion de l'événement de fermeture de la fenêtre
    mlx_hook(game_data->win, 17, 1L << 0, exit_game, game_data);

    // Boucle principale
    mlx_loop(game_data->mlx);

    int i = 0;

    game_data->mlx = mlx_init();
    game_data->win = mlx_new_window(game_data->mlx, 720, 720, "Cube3D");

    mlx_hook(game_data->win, 17, 1L << 0, exit_game, game_data);
    
    float dist = 30;
    while (i < 72)
        draw_vertical_line(game_data, dist++,i++);

    mlx_loop(game_data->mlx);
}*/