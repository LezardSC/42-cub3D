/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:47:44 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/19 14:12:42 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

enum e_infos {
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
};

typedef struct s_data
{
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
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*est_path;
}			t_data;

int		main(int argc, char **argv);
int		init_param(t_data *param);

//parsing
int		is_name_correct(t_data *param);
int		error_parsing(int num_error);
int		map_parsing(t_data *param);
int		is_line_map(char *buf);
int		check_infos(t_data *param);
int		fill_textures_colors(char *buf, t_data *param);

//free
int		free_all_param(t_data *param);
//int		free_init(t_data *param);

//utils
void	print_double_char(char **str);
int		ft_strlen_space(char *str);
#endif