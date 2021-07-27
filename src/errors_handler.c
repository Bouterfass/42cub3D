/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:26:56 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:27:00 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_ray(t_game *g)
{
	if (g->sprite.sorted)
		free(g->sprite.sorted);
	if (g->sprite.dist)
		free(g->sprite.dist);
	if (g->sxy)
		free(g->sxy);
	if (g->sprite.zbuffer)
		free(g->sprite.zbuffer);
	exit_game(g);
}

void	get_err(char *message, t_game *g)
{
	int	i;

	i = -1;
	printf("%s.\n", message);
	g->map->exit = 1;
	if (g->map->map)
	{
		while (++i < g->map->mapy)
			free(g->map->map[i]);
		free(g->map->map);
	}
	if (g->map->notext)
		free(g->map->notext);
	if (g->map->sotext)
		free(g->map->sotext);
	if (g->map->wetext)
		free(g->map->wetext);
	if (g->map->eatext)
		free(g->map->eatext);
	if (g->map->sprite)
		free(g->map->sprite);
	free_ray(g);
}
