/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:46:23 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:46:29 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_start_end(t_game *g)
{
	if (g->sprite.drawstarty < 0)
		g->sprite.drawstarty = 0;
	g->sprite.drawendy = g->sprite.sprheight / 2 + g->map->ry / 2;
	if (g->sprite.drawendy >= g->map->ry)
		g->sprite.drawendy = g->map->ry;
	g->sprite.sprwidth = abs((int)(g->map->ry / (g->sprite.transy)));
	g->sprite.drawstartx = -g->sprite.sprwidth / 2 + g->sprite.sprscreenx;
	if (g->sprite.drawstartx < 0)
		g->sprite.drawstartx = 0;
	g->sprite.drawendx = g->sprite.sprwidth / 2 + g->sprite.sprscreenx;
	if (g->sprite.drawendx >= g->map->rx)
		g->sprite.drawendx = g->map->rx;
}

void	set_sprite(t_game *g, int i)
{
	g->sprite.spritex = g->sxy[g->sprite.sorted[i]].x - g->ray.posx;
	g->sprite.spritey = g->sxy[g->sprite.sorted[i]].y - g->ray.posy;
	g->sprite.invdet = 1.0 / (g->ray.planx * g->ray.diry
			- g->ray.dirx * g->ray.plany);
	g->sprite.transx = g->sprite.invdet * (g->ray.diry
			* g->sprite.spritex - g->ray.dirx * g->sprite.spritey);
	g->sprite.transy = g->sprite.invdet * (-g->ray.plany
			* g->sprite.spritex + g->ray.planx * g->sprite.spritey);
	g->sprite.sprscreenx = (int)((g->map->rx / 2) * (1 + g->sprite.transx
				/ g->sprite.transy));
	g->sprite.sprheight = abs((int)(g->map->ry / (g->sprite.transy)));
	g->sprite.drawstarty = -g->sprite.sprheight / 2 + g->map->ry / 2;
	set_start_end(g);
}
