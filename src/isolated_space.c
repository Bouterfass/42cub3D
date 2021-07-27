/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isolated_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:34:32 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:34:48 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	isolated_space(t_game *g, int x, int y)
{
	int	j;
	int	left;
	int	right;

	j = y;
	left = 0;
	right = 0;
	while (j >= 0)
	{
		if (g->map->map[x][j] == '1' || g->map->map[x][j] == '0')
			left = 1;
		j--;
	}
	j = y;
	while (j < g->map->mapx)
	{
		if (g->map->map[x][j] == '1' || g->map->map[x][j] == '0')
			right = 1;
		j++;
	}
	return (left && right);
}
