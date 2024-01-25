/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:47:23 by jrenault          #+#    #+#             */
/*   Updated: 2024/01/19 18:28:27 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	print_double_char(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}

int	ft_strlen_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\n')
		i++;
	return (i);
}

int	is_space_or_newline(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] != ' ' && buf[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*go_to_map(t_data *param)
{
	char	*buf;

	param->nb_lines = 0;
	buf = get_next_line(param->fd);
	if (!buf)
		return (ft_printf("Error\nget_next_line error\n"), NULL);
	ft_printf("buf1: %s\n", buf);
	while (buf && param->nb_lines <= param->beginning_map)
	{
		free(buf);
		buf = get_next_line(param->fd);
		if (!buf)
			return (ft_printf("Error\nget_next_line error\n"), NULL);
		param->nb_lines++;
	}
	ft_printf("buf2: %s\n", buf);
	param->nb_lines--;
	return (buf);
}
