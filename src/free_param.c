#include "../header/cub3d.h"

int	free_all_param(t_data *param)
{
	int	i;

	i = 0;
	if (param->map)
	{
		while (param->map && param->map[i])
		{
			free(param->map[i]);
			i++;
		}
		free(param->map);
	}
	i = 0;
	if (param->map_infos)
	{
		while (param->map_infos && param->map_infos[i])
		{
			free(param->map_infos[i]);
			i++;
		}
		free(param->map_infos);
	}
	// if (param->map_tmp)
	// {
	// 	i = 0;
	// 	while (param->map_tmp && param->map_tmp[i])
	// 	{
	// 		free(param->map_tmp[i]);
	// 		i++;
	// 	}
	// 	free(param->map_tmp);
	// }
	return (0);
}

// int	free_init(t_data *param)
// {
// 	mlx_destroy_image(param->mlx, param->draw.ground);
// 	mlx_destroy_image(param->mlx, param->draw.escape);
// 	mlx_destroy_image(param->mlx, param->draw.item);
// 	mlx_destroy_image(param->mlx, param->draw.player);
// 	mlx_destroy_image(param->mlx, param->draw.wall_center);
// 	return (0);
// }
