/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fisheye.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:48:10 by tmalidi           #+#    #+#             */
/*   Updated: 2024/04/22 11:29:52 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int  anti_fisheye(t_ray_data *ray, t_data *gd)
{
    double ray_projection;
    double angle;

    if (ray->id > (WINDOW_WIDTH - 1) / 2)
		angle = gd->angle * ((double)(WINDOW_WIDTH / (double)2 - (double)ray->id));
	else
		angle = gd->angle * ((((double)WINDOW_WIDTH - (double)ray->id) - ((double)WINDOW_WIDTH / (double)2)));

    ray_projection = 0.5f * tan(angle) / tan(gd->copy_angle);
    return (roundf(WINDOW_WIDTH * (0.5f - ray_projection)));
}