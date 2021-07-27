/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:19:51 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:20:30 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	*g;

	g = (t_game *)malloc(sizeof(t_game));
	g->map = (t_mapinfo *)malloc(sizeof(t_mapinfo));
	init_game(g);
	if (ac == 2 || (ac == 3 && !ft_memcmp(av[2], "--save", 6)))
	{
		if (ac == 3)
			g->save = 1;
		cub3d(g->map->file = av[1], g);
	}
	else
		get_err("Error\n Invalid arguments", g);
	return (0);
}
