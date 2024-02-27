#include "../../header/cub3d.h"

static float	calculate_distance(int x1, int y1, int x2, int y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

float other_draw_line(t_data *gd, int x1, int y1, int x2, int y2, int color)
{
	(void)color;
		
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx, sy;

	if (x1 < x2)
		sx = 1;
	else
		sx = -1;

	if (y1 < y2)
		sy = 1;
	else
		sy = -1;

	int err = dx - dy;
	while (1)
	{
		my_mlx_pixel_put_map(&gd->drawmap, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break;

		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
	if (x1 != x2 || y1 != y2)
	{
		ft_printf("distance == %f\n", calculate_distance(gd->player.pos_x, gd->player.pos_y, x1, y1));
		return (calculate_distance(gd->player.pos_x, gd->player.pos_y, x1, y1));
	}
	return (-1);
		//draw_vertical_line(gd, calculate_distance(gd->pos_x, gd->pos_y, x1, y1));
}

float draw_line(t_data *gd, int x1, int y1, int x2, int y2, int color)
{
	(void)color;
		
	int	dx = abs(x2 - x1);
	int	dy = abs(y2 - y1);
	int	sx;
	int	sy;

	if (x1 < x2)
		sx = 1;
	else
		sx = -1;

	if (y1 < y2)
		sy = 1;
	else
		sy = -1;

	int err = dx - dy;
	while ((x1 < 400 || y1 < 200 +1) || (x1 > 440 - 2 || y1 > 240 - 1))
	{
		//mlx_pixel_put(gd->mlx, gd->win, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break;

		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
	if (x1 != x2 || y1 != y2)
	{
		ft_printf("distance == %f\n", calculate_distance(gd->player.pos_x, gd->player.pos_y, x1, y1));
		return (calculate_distance(gd->player.pos_x, gd->player.pos_y, x1, y1));
	}
	return (-1);
}