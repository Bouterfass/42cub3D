/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:40:07 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:40:10 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_sprite2(t_game *g, int i, int j, int v)
{
	i = i - 1;
	while (++i < g->map->mapy)
	{
		j = -1;
		while (++j < g->map->mapx)
		{
			if (g->map->map[i][j] == '2')
			{
				g->sxy[v].x = (double)i + 0.5;
				g->sxy[v].y = (double)j + 0.5;
				v++;
			}
		}
	}
}

int	init_sprite(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	g->sprite.total = 0;
	while (++i < g->map->mapy)
	{
		j = -1;
		while (++j < g->map->mapx)
			if (g->map->map[i][j] == '2')
				g->sprite.total++;
	}
	g->sxy = (t_sprxy *)malloc(sizeof(t_sprxy) * g->sprite.total);
	if (!(g->sxy))
		get_err("Error malloc", g);
	g->sprite.sorted = (int *)malloc(sizeof(int) * g->sprite.total);
	if (!(g->sprite.sorted))
		get_err("Error malloc", g);
	g->sprite.dist = (double *)malloc(sizeof(double) * g->sprite.total);
	if (!(g->sprite.dist))
		get_err("Error malloc", g);
	init_sprite2(g, 0, 0, 0);
	set_mlx(g);
	return (0);
}

void	ft_swap(t_game *g)
{
	void	*tmp;

	tmp = g->data.img;
	g->data.img = g->data.img2;
	g->data.img2 = tmp;
	tmp = g->data.addr;
	g->data.addr = g->data.addr2;
	g->data.addr2 = tmp;
}
