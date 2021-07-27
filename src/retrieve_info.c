/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:35:40 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:35:45 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	retrieve_info2(t_game *g)
{	
	count_text(g);
	if (get_mapline(g->map) == 0)
		get_err("Error\ncannot find the map", g);
	if (g->map->countnot > 1 || g->map->countsot > 1 || g->map->counteat > 1
		|| g->map->countwet > 1 || g->map->countst > 1)
		get_err("Error\ntoo much textures", g);
	if (g->map->countnot == 0 || g->map->countsot == 0 || g->map->counteat == 0
		|| g->map->countwet == 0 || g->map->countst == 0)
		get_err("Error\na texture is missing", g);
	if (g->map->countcc == 0 || g->map->countfc == 0)
		get_err("Error\na color is missing", g);
	if (g->map->countcc > 1 || g->map->countfc > 1)
		get_err("Error\ntoo much colors", g);
	if (g->map->countres == 0)
		get_err("Error\nresolution is missing", g);
	if (g->map->countres > 1)
		get_err("Error\nat least two resolution lines detected", g);
}

void	retrieve_info(t_game *g)
{
	int			endl;
	char		*line;

	endl = 1;
	line = NULL;
	g->map->fd = open(g->map->file, O_RDONLY);
	if ((g->map->fd) == -1)
		get_err("Error\ncannot open the file", g);
	while (endl > 0)
	{
		endl = get_next_line(g->map->fd, &line);
		if (!is_mapline(line))
		{
			getinfo(trimstr(line, " \t\v\r\f"), g);
			g->map->startmap++;
			free(line);
		}
		else if (is_mapline(line))
			get_mapinfo(line, g);
	}
	close(g->map->fd);
	retrieve_info2(g);
	init_sprite(g);
}
