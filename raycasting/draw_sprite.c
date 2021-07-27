/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:38:08 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:38:10 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_sprite(t_game *g, int y, int texx, int stripe)
{
	int		d;
	int		texy;

	while (y < g->sprite.drawendy)
	{
		d = y * 256 - g->map->ry * 128 + g->sprite.sprheight * 128;
		texy = ((d * g->text[4].height) / g->sprite.sprheight) / 256;
		if (g->text[4].addr[texy * g->text[4].line_length / 4 \
				+ texx] != 0x00000000)
		{
			g->data.addr[y * g->data.line_length / 4 + stripe] \
				= g->text[4].addr[texy * g->text[4].line_length \
				/ 4 + texx];
		}
		y++;
	}
}
