/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:22:53 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:22:58 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_diag1(t_game *g, int x, int y)
{
	int	j;
	int	i;
	int	left;
	int	right;

	i = x;
	j = y;
	left = 0;
	right = 0;
	while (i < g->map->mapy && j < g->map->mapx)
	{
		if (g->map->map[i][j] == '1')
			left = 1;
		i++;
		j++;
	}
	i = x + 1;
	j = y + 1;
	while (--i >= 0 && --j >= 0)
	{
		if (g->map->map[i][j] == '1')
			right = 1;
	}
	return (left && right);
}

int	check_diag2(t_game *g, int x, int y)
{
	int	i;
	int	j;
	int	left;
	int	right;

	i = x;
	j = y;
	left = 0;
	right = 0;
	while (i < g->map->mapy && j >= 0)
	{
		if (g->map->map[i][j] == '1')
			left = 1;
		i++;
		j--;
	}
	i = x + 1;
	j = y - 1;
	while (--i >= 0 && ++j < g->map->mapx)
	{
		if (g->map->map[i][j] == '1')
			right = 1;
	}
	return (left && right);
}
