/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:29:39 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:29:45 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../includes/cub3d.h"

void	get_mapinfo(char *line, t_game *g)
{
	if (is_mapline(line) && g->map->map == NULL)
		getmapsize(line, g);
	else if (g->map->map)
	{
		weird_map(g);
		is_closed(g);
		count_nseo(g);
		count_zero(g);
	}
}
