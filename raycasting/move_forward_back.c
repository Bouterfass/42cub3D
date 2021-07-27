/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:42:45 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:42:47 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward_back2(t_game *g)
{
	if (g->data.back == 1)
	{
		if (g->map->map[(int)(g->ray.posx - (g->ray.dirx
					* g->ray.m_speed * 2))][(int)(g->ray.posy)] == '0')
			g->ray.posx -= g->ray.dirx * g->ray.m_speed;
		if (g->map->map[(int)(g->ray.posx)][(int)(g->ray.posy -
				(g->ray.diry * g->ray.m_speed * 2))] == '0')
			g->ray.posy -= g->ray.diry * g->ray.m_speed;
	}
}

void	move_forward_back(t_game *g)
{
	if (g->data.forward == 1)
	{
		if (g->map->map[(int)(g->ray.posx + (g->ray.dirx
					* g->ray.m_speed * 2))][(int)g->ray.posy] == '0')
			g->ray.posx += g->ray.dirx * g->ray.m_speed;
		if (g->map->map[(int)(g->ray.posx)][(int)(g->ray.posy +
				(g->ray.diry * g->ray.m_speed * 2))] == '0')
			g->ray.posy += g->ray.diry * g->ray.m_speed;
	}
	move_forward_back2(g);
}

void	move_left_right(t_game *g)
{
	if (g->data.right == 1)
	{
		if (g->map->map[(int)(g->ray.posx + g->ray.diry * (g->ray.m_speed
					* 2))][(int )g->ray.posy] == '0')
			g->ray.posx += g->ray.diry * g->ray.m_speed;
		if (g->map->map[(int)g->ray.posx][(int)(g->ray.posy
			- g->ray.dirx * (g->ray.m_speed * 2))] == '0')
			g->ray.posy -= g->ray.dirx * g->ray.m_speed;
	}
	if (g->data.left == 1)
	{
		if (g->map->map[(int)(g->ray.posx - g->ray.diry
				* (g->ray.m_speed * 2))][(int)g->ray.posy] == '0')
			g->ray.posx -= g->ray.diry * g->ray.m_speed;
		if (g->map->map[(int)g->ray.posx][(int)(g->ray.posy
			+ g->ray.dirx * (g->ray.m_speed * 2))] == '0')
			g->ray.posy += g->ray.dirx * g->ray.m_speed;
	}
}
