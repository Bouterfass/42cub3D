/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:35:28 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:35:32 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(char **str, t_mapinfo *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\n");
	while (i < map->mapy)
	{
		while (j < map->mapx)
		{
			printf("%c", str[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
}

void	print_mapinfo(t_mapinfo *m)
{
	int	i;

	i = 0;
	printf("resolution x = %d\n", m->rx);
	printf("resolution y = %d\n", m->ry);
	printf("notext = %s\n", m->notext);
	printf("sotext = %s\n", m->sotext);
	printf("wetext = %s\n", m->wetext);
	printf("eatext = %s\n", m->eatext);
	printf("sprite = %s\n", m->sprite);
	printf("floor colors = [%d, %d, %d]\n",
		m->floorcol[0], m->floorcol[1], m->floorcol[2]);
	printf("ceiling colors = [%d, %d, %d]\n",
		m->ceilingcol[0], m->ceilingcol[1], m->ceilingcol[2]);
	printf("\nmapx -> %d\n mapy -> %d", m->mapx, m->mapy);
	print_map(m->map, m);
}
