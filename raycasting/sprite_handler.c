/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:50:23 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:50:25 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sprite_handler(t_game *g)
{
	int	i;
	int	j;
	int	stripe;
	int	texx;

	i = -1;
	sort_by_dist(g);
	while (++i < g->sprite.total)
	{
		set_sprite(g, i);
		stripe = g->sprite.drawstartx;
		while (stripe < g->sprite.drawendx)
		{
			texx = (int)(256 * (stripe - (-g->sprite.sprwidth / 2
							+ g->sprite.sprscreenx)) * g->text[4].width
					/ g->sprite.sprwidth) / 256;
			if (g->sprite.transy > 0 && stripe >= 0 && stripe < g->map->rx
				&& g->sprite.transy < g->sprite.zbuffer[stripe])
			{
				j = g->sprite.drawstarty;
				draw_sprite(g, j, texx, stripe);
			}
			stripe++;
		}
	}
}
