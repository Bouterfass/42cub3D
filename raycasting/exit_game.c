/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:38:18 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:38:45 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_game(t_game *g)
{
	if (g->map->exit == 0)
		get_err("Bye", g);
	if (g->data.img)
		mlx_destroy_image(g->data.mlx_ptr, g->data.img);
	if (g->text[0].img)
		mlx_destroy_image(g->data.mlx_ptr, g->text[0].img);
	if (g->text[1].img)
		mlx_destroy_image(g->data.mlx_ptr, g->text[1].img);
	if (g->text[2].img)
		mlx_destroy_image(g->data.mlx_ptr, g->text[2].img);
	if (g->text[3].img)
		mlx_destroy_image(g->data.mlx_ptr, g->text[3].img);
	if (g->text[4].img)
		mlx_destroy_image(g->data.mlx_ptr, g->text[4].img);
	if (g->data.mlx_win)
		mlx_destroy_window(g->data.mlx_ptr, g->data.mlx_win);
	if (g->data.mlx_ptr)
	{
		mlx_destroy_display(g->data.mlx_ptr);
		free(g->data.mlx_ptr);
		g->data.mlx_ptr = NULL;
	}
	exit(0);
}
