/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:39:49 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:39:52 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_deltas(t_game *g)
{
	if (g->ray.raydiry == 0)
		g->ray.deltadistx = 0;
	else if (g->ray.raydirx == 0)
		g->ray.deltadistx = 1;
	else
		g->ray.deltadistx = sqrt(1 + (g->ray.raydiry \
					* g->ray.raydiry) / (g->ray.raydirx \
					* g->ray.raydirx));
	if (g->ray.raydirx == 0)
		g->ray.deltadisty = 0;
	else if (g->ray.raydiry == 0)
		g->ray.deltadisty = 1;
	else
		g->ray.deltadisty = sqrt(1 + (g->ray.raydirx \
					* g->ray.raydirx) / (g->ray.raydiry \
					* g->ray.raydiry));
}

void	init_raycasting(t_game *g)
{
	g->ray.hit = 0;
	g->ray.perpwalldist = 0;
	g->ray.camera = 2 * g->ray.x / (double)g->map->rx - 1;
	g->ray.raydirx = g->ray.dirx + g->ray.planx * g->ray.camera;
	g->ray.raydiry = g->ray.diry + g->ray.plany * g->ray.camera;
	g->ray.mapx = (int)g->ray.posx;
	g->ray.mapy = (int)g->ray.posy;
	g->ray.m_speed = 0.15;
	g->ray.r_speed = 0.0500;
	get_deltas(g);
}
