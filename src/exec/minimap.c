/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:40:59 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/27 00:24:33 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

typedef struct s_pixel {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_pixel;

void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_length + x
			* (pixel->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_square_put(t_pixel *pixel, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < pixel->width)
	{
		while (j < pixel->height)
		{
			my_mlx_pixel_put(pixel, x + i, y + j, color);
			j++;
		}
		j = 0;
		i++;
	}
}

void	my_mlx_circle_put(t_pixel *pixel, int center_x, int center_y, int radius, int color)
{
	int	x;
	int	y;
	int	radiusError;

	x = radius;
	y = 0;
	radiusError = 1 - x;
    while (x >= y)
	{
        int i = center_x - x;
        while (i <= center_x + x) {
            my_mlx_pixel_put(pixel, i, center_y + y, color);
            my_mlx_pixel_put(pixel, i, center_y - y, color);
            i++;
        }

        i = center_x - y;
        while (i <= center_x + y) {
            my_mlx_pixel_put(pixel, i, center_y + x, color);
            my_mlx_pixel_put(pixel, i, center_y - x, color);
            i++;
        }

        y++;

        if (radiusError < 0)
            radiusError += 2 * y + 1;
        else {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}

int	show_minimap(t_data *param)
{
	int		x;
	int		y;
	t_pixel	img;

	x = 0;
	y = 0;
	img.img = mlx_new_image(param->mlx,
			(param->max_x * 72), (param->max_y * 72));
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.width = 14;
	img.height = 14;
	while (param->map[y])
	{
		while (param->map[y][x])
		{
			if (param->map[y][x] == '1')
				my_mlx_square_put(&img, (x * 14), (y * 14), 0x00FF0000);
			if (param->map[y][x] == 'N')
				my_mlx_circle_put(&img, (x * 14) + 7, (y * 14) + 7, 7, 0x00FF0000);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(param->mlx, param->win, img.img, 0, 0);
	return (0);
}
