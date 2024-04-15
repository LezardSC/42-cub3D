#include "../header/cub3d.h"

void	draw_floor(t_data *param)
{
	int			i;
	int			j;
	uint32_t	sky;
	uint32_t	floor;

	i = 0;
	sky = convert_into_hexa(param->sky_color);
	floor = convert_into_hexa(param->floor_color);
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT / 2)
			my_mlx_pixel_put(&param->pixel, i, j++, sky);
		while (j < WIN_HEIGHT)
			my_mlx_pixel_put(&param->pixel, i, j++, floor);
		i++;
	}
}

int show_map(t_data *param)
{
    draw_floor(param);
	if (show_minimap(param) == 1)
		return (free_all_param(param), mlx_destroy_display(param->mlx),
			free(param->mlx), 1);
    return (0);
}