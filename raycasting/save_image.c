/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:44:00 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:44:05 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_header(t_game *g)
{
	int	tmp;

	write(g->map->fd, "BM", 2);
	tmp = 14 + 40 + 4 * g->map->rx * g->map->ry;
	write(g->map->fd, &tmp, 4);
	tmp = 0;
	write(g->map->fd, &tmp, 2);
	write(g->map->fd, &tmp, 2);
	tmp = 54;
	write(g->map->fd, &tmp, 4);
	tmp = 40;
	write(g->map->fd, &tmp, 4);
	write(g->map->fd, &g->map->rx, 4);
	write(g->map->fd, &g->map->ry, 4);
	tmp = 1;
	write(g->map->fd, &tmp, 2);
	write(g->map->fd, &g->data.bpp, 2);
	tmp = 0;
	write(g->map->fd, &tmp, 4);
	write(g->map->fd, &tmp, 4);
	write(g->map->fd, &tmp, 4);
	write(g->map->fd, &tmp, 4);
	write(g->map->fd, &tmp, 4);
	write(g->map->fd, &tmp, 4);
}

void	save_image(t_game *g)
{
	int	i;
	int	j;

	j = g->map->ry;
	g->map->fd = open("./screenshot.bmp", O_CREAT | O_RDWR);
	if ((g->map->fd == -1))
		get_err("Error\ncannot save image", g);
	ft_header(g);
	while (j >= 0)
	{
		i = 0;
		while (i < g->map->rx)
		{
			write(g->map->fd, &g->data.addr[j * g->data.line_length / 4 + i],
				4);
			i++;
		}
		j--;
	}
	system("chmod 777 screenshot.bmp");
	exit(0);
}
