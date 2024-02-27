/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:29:57 by tmalidi           #+#    #+#             */
/*   Updated: 2024/02/26 18:30:33 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int exit_game(t_data *game_data)
{
    mlx_destroy_window(game_data->mlx, game_data->win2);
    mlx_destroy_display(game_data->mlx);
    exit(0);
}