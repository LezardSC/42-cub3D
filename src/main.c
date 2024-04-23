/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:02:43 by jrenault          #+#    #+#             */
/*   Updated: 2024/04/22 16:38:02 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	check_argc(int argc)
{
	if (argc < 2)
		return (ft_printf("Error\nNo map given to the program.\n"),
			1);
	if (argc > 2)
		return (ft_printf("Error\nToo many arguments.\n"), 1);
	return (0);
}

static int	parsing_and_error(t_data *param, char *name)
{
	if (init_param(param) == 1)
		return (ft_printf("Error\nError in initialization.\n"), 1);
	param->map_name = ft_strdup(name);
	if (!param->map_name)
		return (1);
	if (is_name_correct(param))
	{
		ft_printf("Error\nThe map is not a valid '.cub'.\n");
		return (1);
	}
	if (map_parsing(param))
		return (1);
	if (check_error(param) == 1)
		return (1);
	return (0);
}

void	end_program(t_data *param, int boolean)
{
	free_all_param(param);
	if (boolean == 3)
		destroy_gi(param);
	if (boolean == 0)
		mlx_destroy_image(param->mlx, param->pixel.img);
	if (boolean == 4)
	{
		destroy_gi(param);
		mlx_destroy_image(param->mlx, param->pixel.img);
		mlx_clear_window(param->mlx, param->win);
		mlx_destroy_window(param->mlx, param->win);
	}
	if (boolean < 2)
	{
		mlx_clear_window(param->mlx, param->win);
		mlx_destroy_window(param->mlx, param->win);
	}
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	close(param->fd);
}

static int	display_map(t_data *param)
{
	param->pixel.img = mlx_new_image(param->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!param->pixel.img)
		return (destroy_gi(param), end_program(param, 1),
			ft_printf("Error\nInit image\n"), 1);
	param->pixel.addr = mlx_get_data_addr(param->pixel.img,
			&param->pixel.bits_per_pixel,
			&param->pixel.line_length, &param->pixel.endian);
	if (show_minimap(param) == 1)
		return (end_program(param, 4), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	param;

	ft_bzero(&param, sizeof(t_data));
	if (check_argc(argc))
		return (1);
	if (parsing_and_error(&param, argv[1]))
		return (free_all_param(&param), close(param.fd), 1);
	param.mlx = mlx_init();
	if (!param.mlx)
		return (free_all_param(&param),
			mlx_destroy_display(param.mlx), free(param.mlx),
			ft_printf("Error\nMlx init error.\n"), 1);
	if (init_pixels(&param) == 1)
		return (end_program(&param, 3), 1);
	param.win = mlx_new_window(param.mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!param.win)
		return (end_program(&param, 3),
			ft_printf("Error\nInit window error.\n"), 1);
	if (display_map(&param) == 1)
		return (1);
	if (ft_put_windows(&param) == 1)
		return (1);
	return (end_program(&param, 0), 0);
}
