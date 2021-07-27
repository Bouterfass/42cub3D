/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:33:38 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:33:41 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game(t_game *g)
{
	init_mapinfo(g);
	g->save = 0;
	g->data.img = NULL;
	g->text[0].img = NULL;
	g->text[1].img = NULL;
	g->text[2].img = NULL;
	g->text[3].img = NULL;
	g->text[4].img = NULL;
	g->data.mlx_win = NULL;
	g->sprite.sorted = NULL;
	g->sprite.dist = NULL;
	g->sprite.zbuffer = NULL;
	g->sxy = NULL;
}
