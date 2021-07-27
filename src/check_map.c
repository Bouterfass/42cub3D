/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:23:23 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:23:34 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_row(t_game *g, int x, int y)
{
	int	j;
	int	left;
	int	right;

	j = y;
	left = 0;
	right = 0;
	while (j >= 0)
	{
		if (g->map->map[x][j] == '1')
			left = 1;
		j--;
	}
	j = y;
	while (j < g->map->mapx)
	{
		if (g->map->map[x][j] == '1')
			right = 1;
		j++;
	}
	return (left && right);
}

int	check_col(t_game *g, int x, int y)
{
	int	j;
	int	up;
	int	down;

	j = x;
	up = 0;
	down = 0;
	while (j >= 0)
	{
		if (g->map->map[j][y] == '1')
			up = 1;
		j--;
	}
	j = x;
	while (j < g->map->mapy)
	{
		if (g->map->map[j][y] == '1')
			down = 1;
		j++;
	}
	return (up && down);
}

int	is_nseo(char c)
{
	if (c == 'N' || c == 'S'
		|| c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	is_closed(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g->map->mapy)
	{
		while (j < g->map->mapx)
		{
			if (g->map->map[i][j] == ' ')
				g->map->map[i][j] = '1';
			if (g->map->map[i][j] == '0' || g->map->map[i][j] == '2'
				|| is_nseo(g->map->map[i][j]))
				if (!check_row(g, i, j) || !check_col(g, i, j)
					|| !check_diag1(g, i, j) || !check_diag2(g, i, j))
					get_err("Error\nmap must be arounded by 1", g);
			j++;
		}
		j = 0;
		i++;
	}
}
