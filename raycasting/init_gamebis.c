/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gamebis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:39:29 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:39:32 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_direction(t_game *g)
{
	if (g->map->startdir == 'N')
		g->ray.dirx = -1;
	if (g->map->startdir == 'S')
		g->ray.dirx = 1;
	if (g->map->startdir == 'W')
		g->ray.diry = -1;
	if (g->map->startdir == 'E')
		g->ray.diry = 1;
	if (g->map->startdir == 'N')
		g->ray.plany = 0.66;
	if (g->map->startdir == 'S')
		g->ray.plany = -0.66;
	if (g->map->startdir == 'W')
		g->ray.planx = -0.66;
	if (g->map->startdir == 'E')
		g->ray.planx = 0.66;
}

void	init_gamebis(t_game *g)
{
	g->sprite.zbuffer = (double *)malloc(sizeof(double) * g->map->rx);
	if (!(g->sprite.zbuffer))
		exit(0);
	g->data.forward = 0;
	g->data.left = 0;
	g->data.right = 0;
	g->data.back = 0;
	g->data.r_left = 0;
	g->data.r_right = 0;
	g->ray.posx = (double)g->map->dx + 0.5;
	g->ray.posy = (double)g->map->dy + 0.5;
	g->ray.planx = 0;
	g->ray.plany = 0;
	g->ray.dirx = 0;
	g->ray.diry = 0;
	init_direction(g);
}
