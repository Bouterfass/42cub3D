/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:48:06 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:48:09 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sort_by_dist2(t_game *g)
{
	int	i;

	i = -1;
	while (++i < g->sprite.total)
	{
		g->sprite.sorted[i] = i;
		g->sprite.dist[i] = ((g->ray.posx - g->sxy[i].x)
				* (g->ray.posx - g->sxy[i].x) + (g->ray.posy
					- g->sxy[i].y) * (g->ray.posy - g->sxy[i].y));
	}
}

void	sort_by_dist(t_game *g)
{
	int		i;
	int		j;
	double	tmp;

	sort_by_dist2(g);
	i = -1;
	while (++i < g->sprite.total)
	{
		j = -1;
		while (++j < g->sprite.total - 1)
		{
			if (g->sprite.dist[j] < g->sprite.dist[j + 1])
			{
				tmp = g->sprite.dist[j];
				g->sprite.dist[j] = g->sprite.dist[j + 1];
				g->sprite.dist[j + 1] = tmp;
				tmp = g->sprite.sorted[j];
				g->sprite.sorted[j] = g->sprite.sorted[j + 1];
				g->sprite.sorted[j + 1] = (int)tmp;
			}
		}
	}
}
