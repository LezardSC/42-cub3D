/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:47:44 by jrenault          #+#    #+#             */
/*   Updated: 2024/02/21 16:10:23 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

enum e_colors
{
	F = 0,
	C = 1
};

enum e_textures
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3
};

typedef struct s_data
{
	int		nb_lines;
	int		fd;
	int		*check_colors;
	int		*textures;
	int		*floor_color;
	int		*sky_color;
	void	*mlx;
	void	*win;
	char	*map_name;
	char	**map;
	char	**map_textures;
	int		max_x;
	int		max_y;
	int		min_y;
	int		pos_x;
	int		pos_y;
	double	x2;
	double	y2;
	double	angle;
	double	copy_angle;
}			t_data;

int		main(int argc, char **argv);
int		init_param(t_data *param);

//parsing
int		is_name_correct(t_data *param);
int		map_parsing(t_data *param);
int		is_line_map(char *buf);
int		check_infos(t_data *param);
int		find_infos(t_data *param);
int		fill_textures_colors(char *buf, t_data *param);
int		check_error(t_data *param);

//free
int		free_all_param(t_data *param);
//int		free_init(t_data *param);

//utils
void	print_double_char(char **str);
int		ft_strlen_space(char *str);
int		is_space_or_newline(char *buf);
char	*go_to_map(t_data *param);

//visuals
void ft_put_windows(t_data *game_data);
void ft_put_3dview(t_data *game_data);

//tools
int	ft_key(int key, t_data *gd);  //prends les inputs
void draw_player_view(t_data *game_data);  //print les rayon
int exit_game(t_data *game_data);
float draw_line(t_data *gd, int x1, int y1, int x2, int y2, int color);
float calculerDistance(int x1, int y1, int x2, int y2);
void draw_vertical_line(t_data *game_data, float dist, int ray);

#endif