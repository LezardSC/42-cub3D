/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:47:57 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/31 16:53:50 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	no_wrong_arguments(t_data *param, int i, int j)
{
	int	n;

	i = 0;
	n = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == 'N' || param->map[i][j] == 'E'
					|| param->map[i][j] == 'W' || param->map[i][j] == 'S')
			{
				param->direction = param->map[i][j];
				n++;
			}
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

static int	near_space_or_empty(t_data *param, int y, int x)
{
	if (y == 0 || y == param->max_y)
		return (1);
	if (x == 0 || x == param->max_x)
		return (1);
	if (param->map[y + 1][x] == ' ' || param->map[y - 1][x] == ' '
		|| param->map[y][x + 1] == ' ' || param->map[y][x - 1] == ' ')
		return (1);
	if (param->map[y + 1][x + 1] == ' ' || param->map[y - 1][x - 1] == ' '
		|| param->map[y - 1][x + 1] == ' ' || param->map[y + 1][x - 1] == ' ')
		return (1);
	return (0);
}

static int	is_map_closed(t_data *param)
{
	int	i;
	int	j;

	i = 0;
	while (i <= param->max_y)
	{
		j = 0;
		while (j <= param->max_x)
		{
			if (param->map[i][j] == '0')
			{
				if (near_space_or_empty(param, i, j) == 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error(t_data *param)
{
	if (no_wrong_arguments(param, 0, 0) == 1)
		return (ft_printf("Error\nInvalid map\n"), 1);
	if (is_map_closed(param) == 1)
		return (ft_printf("Error\nMap isn't closed\n"), 1);
	return (0);
}
