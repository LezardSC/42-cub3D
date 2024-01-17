/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:55:54 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/17 18:20:26 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	is_line_map(char *buf)
{
	int	i;

	i = 0;
	if (buf[0] == '1' || buf[0] == '0' || (buf[0] == 'N' && buf[1] != 'O'))
		return (1);
	else if (buf[0] == ' ')
	{
		while (buf[i])
		{
			if (buf[i] == '1' || buf[i] == '0' || buf[i] == 'N')
				return (1);
			i++;
		}
	}
	return (0);
}

// static int	find_max_x(t_data *param)
// {
// 	(void)param;
// 	return (0);
// }

void	deal_with_empty_lines(t_data *param, int fd, int i)
{
	while (param->map_infos[i][0] == '\n')
	{
		free(param->map_infos[i]);
		param->map_infos[i] = get_next_line(fd);
	}
}

int	info_map_parsing(t_data *param, int i)
{
	(void)param;
	(void)i;
	return (0);
	// int	fd;

	// fd = open(param->map_name, O_RDONLY);
	// if (fd == -1)
	// 	return (error_parsing(1), close(fd), 1);
	// while (++i < param->min_y)
	// {
	// 	param->map_infos[i] = get_next_line(fd);
	// 	if (!param->map_infos[i])
	// 		return (close(fd), 1);
	// 	deal_with_empty_lines(param, fd, i);
	// 	if (param->map_infos[i][ft_strlen(param->map_infos[i]) - 1] == '\n')
	// 		param->map_infos[i][ft_strlen(param->map_infos[i]) - 1] = '\0';
	// }
	// param->map_infos[i] = NULL;
	// i = -1;
	// while (++i < (param->max_y - param->min_y))
	// {
	// 		param->map[i] = get_next_line(fd);
	// 	if (!param->map[i])
	// 		return (close(fd), 1);
	// 	if (param->map[i][ft_strlen(param->map[i]) - 1] == '\n')
	// 		param->map[i][ft_strlen(param->map[i]) - 1] = '\0';
	// }
	// param->max_x = find_max_x(param);
	// return (param->map[i] = NULL, close(fd), 0);
}
