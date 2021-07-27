/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:43:25 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:43:27 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_left(t_game *g, double olddirx)
{
	double	oldplanex;

	if (g->data.r_left == 1)
	{
		olddirx = g->ray.dirx;
		oldplanex = g->ray.planx;
		g->ray.dirx = g->ray.dirx * cos(g->ray.r_speed)
			- g->ray.diry * sin(g->ray.r_speed);
		g->ray.diry = olddirx * sin(g->ray.r_speed)
			+ g->ray.diry * cos(g->ray.r_speed);
		g->ray.planx = g->ray.planx * cos(g->ray.r_speed)
			- g->ray.plany * sin(g->ray.r_speed);
		g->ray.plany = oldplanex * sin(g->ray.r_speed)
			+ g->ray.plany * cos(g->ray.r_speed);
	}
}

void	rotate_left_right(t_game *g)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = g->ray.planx;
	olddirx = g->ray.dirx;
	if (g->data.r_right == 1)
	{
		g->ray.dirx = g->ray.dirx * cos(-g->ray.r_speed)
			- g->ray.diry * sin(-g->ray.r_speed);
		g->ray.diry = olddirx * sin(-g->ray.r_speed)
			+ g->ray.diry * cos(-g->ray.r_speed);
		g->ray.planx = g->ray.planx * cos(-g->ray.r_speed)
			- g->ray.plany * sin(-g->ray.r_speed);
		g->ray.plany = oldplanx * sin(-g->ray.r_speed)
			+ g->ray.plany * cos(-g->ray.r_speed);
	}
	rotate_left(g, olddirx);
}
