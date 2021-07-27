/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:37:53 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:37:55 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_texture(t_game *g)
{
	if (g->ray.side == 0 && g->ray.raydirx < 0)
		g->t.texdir = 0;
	if (g->ray.side == 0 && g->ray.raydirx >= 0)
		g->t.texdir = 1;
	if (g->ray.side == 1 && g->ray.raydiry < 0)
		g->t.texdir = 2;
	if (g->ray.side == 1 && g->ray.raydiry >= 0)
		g->t.texdir = 3;
	if (g->ray.side == 0)
		g->t.wallx = g->ray.posy + g->ray.perpwalldist
			* g->ray.raydiry;
	else
		g->t.wallx = g->ray.posx + g->ray.perpwalldist
			* g->ray.raydirx;
	g->t.wallx -= floor((g->t.wallx));
}

void	draw_texture(t_game *g, int x, int y)
{
	y = g->ray.drawstart - 1;
	init_texture(g);
	g->t.step = 1.0 * g->text[0].height / g->ray.lineheight;
	g->t.texx = (int)(g->t.wallx * (double)g->text
		[g->t.texdir].width);
	if (g->ray.side == 0 && g->ray.raydirx > 0)
		g->t.texx = g->text[g->t.texdir].width
			- g->t.texx - 1;
	if (g->ray.side == 1 && g->ray.raydiry < 0)
		g->t.texx = g->text[g->t.texdir].width
			- g->t.texx - 1;
	g->t.texpos = (g->ray.drawstart - g->map->ry / 2
			+ g->ray.lineheight / 2) * g->t.step;
	while (++y <= g->ray.drawend)
	{
		g->t.texy = (int)g->t.texpos
			& (g->text[g->t.texdir].height - 1);
		g->t.texpos += g->t.step;
		if (y < g->map->ry && x < g->map->rx)
			g->data.addr[y * g->data.line_length / 4 + x]
				= g->text[g->t.texdir].addr[g->t.texy
				* g->text[g->t.texdir].line_length / 4
				+ g->t.texx];
	}
}

int	draw_ray(t_game *g)
{
	int	i;
	int	j;
	int	floor;
	int	ceiling;

	j = -1;
	floor = createRGB(g->map->floorcol[0], g->map->floorcol[1],
			g->map->floorcol[2]);
	ceiling = createRGB(g->map->ceilingcol[0], g->map->ceilingcol[1],
			g->map->ceilingcol[2]);
	g->ray.drawend = g->map->ry - g->ray.drawstart;
	i = g->ray.drawend;
	while (++j < g->ray.drawstart)
		g->data.addr[j * g->data.line_length / 4
			+ g->ray.x] = ceiling;
	if (j <= g->ray.drawend)
		draw_texture(g, g->ray.x, j);
	j = i;
	while (++j < g->map->ry)
		g->data.addr[j * g->data.line_length / 4
			+ g->ray.x] = floor;
	return (0);
}
