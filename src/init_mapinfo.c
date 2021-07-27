/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:33:50 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:34:07 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mapinfo2(t_game *g)
{
	g->map->linelength = 0;
	g->map->readlines = 0;
	g->map->emptyline = 0;
	g->map->startmap = 0;
	g->map->countlinemap = 0;
	g->map->countnot = 0;
	g->map->countsot = 0;
	g->map->counteat = 0;
	g->map->countwet = 0;
	g->map->countst = 0;
	g->map->dx = 0;
	g->map->dy = 0;
	g->map->startdir = 0;
	g->map->countfc = 0;
	g->map->countcc = 0;
	g->map->countres = 0;
	g->map->exit = 0;
	g->map->scrx = 0;
	g->map->scry = 0;
	g->map->once = 0;
}

void	init_mapinfo(t_game *g)
{
	int	i;

	i = 0;
	g->map->rx = 0;
	g->map->ry = 0;
	g->map->notext = NULL;
	g->map->sotext = NULL;
	g->map->wetext = NULL;
	g->map->eatext = NULL;
	g->map->sprite = NULL;
	g->map->floorcol[0] = -1;
	g->map->floorcol[1] = -1;
	g->map->floorcol[2] = -1;
	g->map->ceilingcol[0] = -1;
	g->map->ceilingcol[1] = -1;
	g->map->ceilingcol[2] = -1;
	g->map->map = NULL;
	g->map->file = NULL;
	g->map->fd = 0;
	g->map->mapx = 0;
	g->map->mapy = 1;
	init_mapinfo2(g);
}
