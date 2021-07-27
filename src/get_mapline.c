/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:29:53 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:29:55 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_mapline(t_mapinfo *map)
{
	int		count;
	int		endl;
	char	*line;

	count = 0;
	endl = 1;
	line = NULL;
	map->fd = open(map->file, O_RDONLY);
	if (map->fd == -1)
	{
		printf("File error: can't read %s\n", map->file);
		return (1);
	}
	while (endl > 0)
	{
		endl = get_next_line(map->fd, &line);
		if (count >= map->startmap)
			if (is_mapline(line))
				map->countlinemap++;
		free(line);
		count++;
	}
	close(map->fd);
	return (map->countlinemap);
}
