/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:47:57 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/18 13:36:10 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

/*
part 1:
-separate infos from the map, and check bot separately

part 2:
-check if we have the four lines of textures and stock them into
variables.
-check if we have the color of ground and sky.
-check if there is no other lines except than empty lines or with spaces
until the map.

part 3:
-check if the map has nothing but 0, 1 or N
-check if the map is closed
-check if there is nothing under the map
*/

/*
recommencer en ouvrant qu'un seul fd et en le faisant passer.
Pas mettre F et C dans le même tableau que les directions, c'est des int
ou un truc du genre.
*/