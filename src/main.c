/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:02:43 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/18 14:48:57 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	check_argc(int argc)
{
	if (argc < 2)
		return (ft_printf("Error\nNo map given to the program."),
			1);
	if (argc > 2)
		return (ft_printf("Error\nToo many arguments."), 1);
	return (0);
}

static int	parsing_and_error(t_data *param, char *name)
{
	init_param(param);
	param->map_name = ft_strdup(name);
	if (!param->map_name)
		return (1);
	if (is_name_correct(param))
	{
		ft_printf("Error\nThe map is not a valid '.cub'.\n");
		return (1);
	}
	if (map_parsing(param))
		return (free(param->map_name), free_all_param(param), 1);
	// if (check_error(param) == 0)
		// return (free(param->map_name), free_all_param(param), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	param;

	if (check_argc(argc))
		return (1);
	if (parsing_and_error(&param, argv[1]))
	{
		free(param.textures);
		free(param.floor_color);
		free(param.sky_color);
		return (1);
	}
	free(param.map_name);
	free(param.textures);
	free(param.floor_color);
	free(param.sky_color);
	return (0);
}
