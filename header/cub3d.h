/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:47:44 by jrenault          #+#    #+#             */
/*   Updated: 2024/03/25 13:55:54 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

# include <math.h>

# define TRUE 			1
# define FALSE			0

# define MINIMAP_HEIGHT	400
# define MINIMAP_WIDTH	400

# define WHITE_COLOR	0x00FFFFFF
# define RED_COLOR		0x00FF0000
# define GREEN_COLOR	0x0000FF00
# define BLUE_COLOR 	0x000000FF
# define BLACK_COLOR	0x00000000
# define YELLOW_COLOR	0x00FFFF00
# define CYAN_COLOR		0x0000FFFF
# define MAGENTA_COLOR	0x00FF00FF
# define GREY_COLOR		0x646464
# define ORANGE_COLOR	0xFF2D00

# define SPEED			0.02
# define ROTATION_SPEED	1 * M_PI / 180.0

# define WINDOW_WIDTH	1920
# define WINDOW_HEIGHT	1080
# define TEX_SIDE		72

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

enum e_keys
{
	ESC = 65307,
	UP = 119,
	UP2 = 100,
	DOWN = 115,
	DOWN2 = 113,
	ROTATE_LEFT = 97,
	ROTATE_LEFT2 = 65361,
	ROTATE_RIGHT = 100,
	ROTATE_RIGHT2 = 65363
};

typedef struct s_pixel
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size;
	int		radius;
}				t_pixel;

typedef struct s_tmp
{
	char	*addr[1080];
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size;
	void	*img;
}				t_tmp;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	angle;
	int		forward;
	int		backward;
	int		rotate_left;
	int		rotate_right;
	int		right;
	int		left;
}				t_player;

typedef struct s_pview
{
	double	cp_x;
	double	cp_y;
	double	radius;
	double	temp_cp_y;
	double	temp_cp_x;
}				t_pview;

typedef struct s_tex_data
{
	int		bpp;
	int		sl;
	int		endian;
	int		original_width;
	int		original_height;
	void	*enlarged_wall;
	char	*enlarged_wall_data;
	int		original_x;
	int		original_y;
	int		original_index;
	int		enlarged_index;
}				t_tex_data;

typedef struct s_data
{
	int			nb_lines;
	int			fd;
	int			*check_colors;
	int			*textures;
	int			*floor_color;
	int			*sky_color;
	void		*mlx;
	void		*win;
	void		*win2;
	char		*map_name;
	char		**map;
	char		**map_textures;
	int			max_x;
	int			max_y;
	int			min_y;
	int			pos_x;
	int			pos_y;
	int			x2;
	int			y2;
	double		angle;
	double		copy_angle;
	void		*gi;
	char		*gi_data;
	int			sl;
	int			bpp;
	int			endian;
	char		*addr;
	double		radius;
	int			sx;
	int			sy;
	int			beginning_map;
	char		direction;
	int			tex_side;
	int			card;
	t_pixel		pixel;
	t_player	player;
	t_tmp		tex_north;
	t_tmp		tex_south;
	t_tmp		tex_east;
	t_tmp		tex_west;
}			t_data;

typedef struct s_ray_data
{
	int	x;
	int	y;
	int	dist;
	int	id;
}				t_ray_data;

typedef struct s_line_data
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	e2;
	int	err;
	int	x1;
	int	y1;
}				t_line_data;

int			main(int argc, char **argv);
int			init_param(t_data *param);
int			init_pixels(t_data *param);
int			is_name_correct(t_data *param);
int			map_parsing(t_data *param);
int			is_line_map(char *buf);
int			check_infos(t_data *param);
int			find_infos(t_data *param);
int			fill_textures_colors(char *buf, t_data *param);
int			check_error(t_data *param);
int			fill_line_map(char *buf, t_data *param, int i);
int			close_win(t_data *param);
int			deal_key(int key, t_data *param);
int			key_release(int key, t_data *param);
int			move_player(t_data *param);
int			show_minimap(t_data *param);
int			move_forward(t_data *param);
int			move_backward(t_data *param);
int			move_left(t_data *param);
int			move_right(t_data *param);
void		my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color);
void		my_mlx_square_put(t_pixel *pixel, int x, int y, int color);
void		my_mlx_circle_put(t_data *param, int color);
int			free_all_param(t_data *param);
void		print_double_char(char **str);
int			ft_strlen_space(char *str);
int			is_space_or_newline(char *buf);
char		*go_to_map(t_data *param);
uint32_t	convert_into_hexa(int *array);
void		ft_put_windows(t_data *game_data);
void		ft_put_3dview(t_data *game_data);
int			ft_key(int key, t_data *gd);
void		draw_player_view(t_data *game_data);
int			exit_game(t_data *game_data);
t_ray_data	draw_line(t_data *gd, int x2, int y2, int ray_id);
float		calc_dist(int x1, int y1, int x2, int y2);
void		draw_vertical_line(t_data *game_data, t_ray_data *ray);
void		draw_floor(t_data *gd);
void		put_pixel_to_image(t_data *gd, int x, int y, int color);
void		making_map(t_data *gd);
int			collision(t_data *gd, int x, int y);
void		left_right_move(int key, t_data *gd);
char		*new_display(t_data *game_data, char *wall_data, int ray);
void		put_image_in_image(t_data *game_data, int x, int y, char *img_data);
int			get_pixel_color(t_data *gd, int x, int y, int ray);
int			is_x_wall(int x, t_data *gd);
void		north_tex(t_data *gd);
void 		south_tex(t_data *gd);
void 		west_tex(t_data *gd);
void 		east_tex(t_data *gd);

#endif 
