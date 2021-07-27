/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sidedists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:39:04 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:39:06 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_vertray(t_game *g)
{
	if (g->ray.side == 0)
		g->ray.perpwalldist = ((double)g->ray.mapx
				- g->ray.posx + (1 - (double)g->ray.stepx)
				/ 2) / g->ray.raydirx;
	else
		g->ray.perpwalldist = ((double)g->ray.mapy
				- g->ray.posy + (1 - (double)g->ray.stepy)
				/ 2) / g->ray.raydiry;
	g->ray.lineheight = (int)(g->map->ry / g->ray.perpwalldist);
	g->ray.drawstart = -g->ray.lineheight / 2 + g->map->ry / 2;
	if (g->ray.drawstart < 0)
		g->ray.drawstart = 0;
	g->ray.drawend = g->ray.lineheight / 2 + g->map->ry / 2;
	if (g->ray.drawend >= g->map->ry || g->ray.drawend < 0)
		g->ray.drawend = g->map->ry - 1;
}

void	wall_collision(t_game *g)
{
	while (g->ray.hit == 0)
	{
		if (g->ray.sidedistx < g->ray.sidedisty)
		{
			g->ray.sidedistx += g->ray.deltadistx;
			g->ray.mapx += g->ray.stepx;
			g->ray.side = 0;
		}
		else
		{
			g->ray.sidedisty += g->ray.deltadisty;
			g->ray.mapy += g->ray.stepy;
			g->ray.side = 1;
		}
		if (g->map->map[g->ray.mapx][g->ray.mapy] == '1')
			g->ray.hit = 1;
	}
	get_vertray(g);
}

void	get_sidedists(t_game *g)
{
	if (g->ray.raydirx < 0)
	{
		g->ray.stepx = -1;
		g->ray.sidedistx = (g->ray.posx - g->ray.mapx)
			* g->ray.deltadistx;
	}
	else
	{
		g->ray.stepx = 1;
		g->ray.sidedistx = (g->ray.mapx + 1.0 - g->ray.posx)
			* g->ray.deltadistx;
	}
	if (g->ray.raydiry < 0)
	{
		g->ray.stepy = -1;
		g->ray.sidedisty = (g->ray.posy - g->ray.mapy)
			* g->ray.deltadisty;
	}
	else
	{
		g->ray.stepy = 1;
		g->ray.sidedisty = (g->ray.mapy + 1.0 - g->ray.posy)
			* g->ray.deltadisty;
	}
	wall_collision(g);
}
