/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:47:57 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/17 18:38:25 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	fill_infos_tab(t_data *param, char *buf)
{
	int	i;

	i = 0;
	ft_printf("buf 2: %s\n", buf);
	if (buf[0] == 'N' && buf[1] == 'O')
		param->infos[NO] += 1;
	if (buf[0] == 'S' && buf[1] == 'O')
		param->infos[SO] += 1;
	if (buf[0] == 'W' && buf[1] == 'E')
		param->infos[WE] += 1;
	if (buf[0] == 'E' && buf[1] == 'A')
		param->infos[EA] += 1;
	if (buf[0] == 'F')
		param->infos[F] += 1;
	if (buf[0] == 'C')
		param->infos[C] += 1;
}

int	check_infos(t_data *param)
{
	int		fd;
	char	*buf;

	fd = open(param->map_name, O_RDONLY);
	if (fd == -1)
		return (error_parsing(1), close(fd), 1);
	buf = get_next_line(fd);
	if (!buf)
		return (close(fd), -2);
	ft_printf("buf 1: %s\n", buf);
	while (buf)
	{
		ft_printf("buf 1: %s\n", buf);
		fill_infos_tab(param, buf);
		free(buf);
		buf = get_next_line(fd);
	}
	free(buf);
	close(fd);
	for (int i = 0; i < 6; i++)
		ft_printf("%d\n", param->infos[i]);
	return (0);
}

int	check_map(t_data *param)
{
	(void)param;
	return (0);
}

int	check_error(t_data *param)
{
	(void)param;
//	int	error_infos;
//	int	error_map;

//	error_infos = check_infos(param);
//	error_map = check_map(param);
	return (1);
}

/*
part 1:
-separate infos from the map, and check bot separately

part 2:
-check if we have the four lines of textures and stock them into
variables.
-check if we have the color of ground and sky.
-check if there is no other lines except than empty lines or with spaces
until the map.

part 3:
-check if the map has nothing but 0, 1 or N
-check if the map is closed
-check if there is nothing under the map
*/

/*
recommencer en ouvrant qu'un seul fd et en le faisant passer.
Pas mettre F et C dans le même tableau que les directions, c'est des int
ou un truc du genre.
*/