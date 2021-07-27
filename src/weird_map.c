/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weird_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:36:36 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:36:38 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_mapline(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' '
			&& str[i] != '2' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E'
			&& str[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int	weird_map(t_game *g)
{
	int		count;
	int		endl;
	char	*line;

	count = 0;
	endl = 1;
	g->map->fd = open(g->map->file, O_RDONLY);
	if ((g->map->fd) == -1)
		get_err("Error\ncannot read file", g);
	while (endl > 0)
	{
		endl = get_next_line(g->map->fd, &line);
		if (count > g->map->startmap
			&& count < g->map->startmap + g->map->mapy)
			if (!check_mapline(line) || empty_line(line) || line[0] == '\0')
				get_err("Error\nwrong line inside map", g);
		if (count >= g->map->startmap + g->map->mapy)
			if (!check_mapline(line) && !empty_line(line))
				get_err("Error\nthe map is not at the end of the file", g);
		free(line);
		count++;
	}
	close(g->map->fd);
	return (0);
}
