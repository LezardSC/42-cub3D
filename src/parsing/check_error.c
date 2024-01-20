/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:47:57 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/20 16:05:07 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

/*
textures check_error:
	-check if path exist and stock it inside a variable
	
map check error:
	-check if map is closed
*/


static int	no_wrong_arguments(t_data *param)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == 'N')
				n++;
			else if (param->map[i][j] != ' '
				&& param->map[i][j] != '1' && param->map[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	if (n != 1)
		return (1);
	return (0);
}

static int	is_map_closed(t_data *param)
{
	(void)param;
	return (0);
}

int	check_error(t_data *param)
{
	if (no_wrong_arguments(param) == 1)
		return (ft_printf("Error\nInvalid map\n"), 1);
	if (is_map_closed(param) == 1)
		return (ft_printf("Error\nMap isn't closed\n"), 1);
	return (0);
}
