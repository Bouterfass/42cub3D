/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_nseo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:23:56 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:23:58 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_nseo(t_game *g)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = -1;
	count = 0;
	while (++i < g->map->mapy)
	{
		while (++j < g->map->mapx)
		{
			if (is_nseo(g->map->map[i][j]))
			{
				g->map->dx = i;
				g->map->dy = j;
				g->map->startdir = g->map->map[i][j];
				g->map->map[i][j] = '0';
				count++;
			}
		}
		j = -1;
	}
	if (count == 0 || count > 1)
		get_err("Error\nneed only one player", g);
	return (count);
}

int	count_zero(t_game *g)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < g->map->mapy)
	{
		while (j < g->map->mapx)
		{
			if (g->map->map[i][j] == '0')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 0 && count_nseo(g) == 0)
		get_err("Error\nno 0 in the map", g);
	return (count);
}
