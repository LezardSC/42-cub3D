#include "../../header/cub3d.h"

// void	draw_player_view(t_data *param)
// {
// 	int i;
// 	double cp_x = param->x2;
// 	double cp_y = param->y2;
// 	double radius = MAP_WIDTH;

// 	i = 1;
// 	while (i < 72)
// 	{
// 		double temp_cp_x = cp_x;
// 		double temp_cp_y = cp_y;
// 		cp_x = temp_cp_x * cos(param->player.angle) - temp_cp_y * sin(param->player.angle);
// 		cp_y = temp_cp_x * sin(param->player.angle) + temp_cp_y * cos(param->player.angle);
// 		cp_x = (cp_x / sqrt(cp_x * cp_x + cp_y * cp_y)) * radius;
// 		cp_y = (cp_y / sqrt(cp_x * cp_x + cp_y * cp_y)) * radius;
// 		if (i > 2)
// 			draw_vertical_line(param, draw_line(param, param->player.pos_x,
// 				param->player.pos_y, param->player.pos_x + cp_x, param->player.pos_y + cp_y, SCARLET_COLOR), i);
// 		i++;
// 	}
// }
