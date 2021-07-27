/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:42:27 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:42:29 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_game *g)
{
	if (keycode == FORWARD_Z)
		g->data.forward = 1;
	else if (keycode == BACK_S)
		g->data.back = 1;
	else if (keycode == RIGHT_D)
		g->data.right = 1;
	else if (keycode == LEFT_Q)
		g->data.left = 1;
	else if (keycode == R_LEFT)
		g->data.r_left = 1;
	else if (keycode == R_RIGHT)
		g->data.r_right = 1;
	else if (keycode == ESC)
		get_err("Bye", g);
	return (1);
}

int	key_release(int keycode, t_game *g)
{
	if (keycode == FORWARD_Z)
		g->data.forward = 0;
	else if (keycode == BACK_S)
		g->data.back = 0;
	else if (keycode == LEFT_Q)
		g->data.left = 0;
	else if (keycode == RIGHT_D)
		g->data.right = 0;
	else if (keycode == R_LEFT)
		g->data.r_left = 0;
	else if (keycode == R_RIGHT)
		g->data.r_right = 0;
	return (1);
}
