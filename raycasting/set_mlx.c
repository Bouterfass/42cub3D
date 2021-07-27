/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:44:18 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:44:20 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	start_raycasting(t_game *g)
{
	g->ray.x = 0;
	while (g->ray.x < g->map->rx)
	{
		init_raycasting(g);
		get_sidedists(g);
		draw_ray(g);
		g->sprite.zbuffer[g->ray.x] = g->ray.perpwalldist;
		g->ray.x++;
	}
	sprite_handler(g);
	if (g->save == 1)
		save_image(g);
	mlx_put_image_to_window(g->data.mlx_ptr, g->data.mlx_win,
		g->data.img, 0, 0);
	move_forward_back(g);
	move_left_right(g);
	rotate_left_right(g);
	ft_swap(g);
	return (0);
}

void	get_screen_size(t_game *g)
{
	if (g->map->rx > g->map->scrx)
		g->map->rx = g->map->scrx;
	if (g->map->ry > g->map->scry)
		g->map->ry = g->map->scry;
}

int	set_mlx(t_game *g)
{
	init_gamebis(g);
	g->data.mlx_ptr = mlx_init();
	mlx_get_screen_size(g->data.mlx_ptr, &g->map->scrx, &g->map->scry);
	get_screen_size(g);
	retrieve_texture(g);
	g->data.img = mlx_new_image(g->data.mlx_ptr, g->map->rx, g->map->ry);
	g->data.addr = (int *)mlx_get_data_addr(g->data.img, &g->data.bpp,
			&g->data.line_length, &g->data.endian);
	if (g->save == 1)
		start_raycasting(g);
	g->data.mlx_win = mlx_new_window(g->data.mlx_ptr, g->map->rx,
			g->map->ry, "Cub3D!");
	g->data.img2 = mlx_new_image(g->data.mlx_ptr, g->map->rx, g->map->ry);
	g->data.addr2 = (int *)mlx_get_data_addr(g->data.img2,
			&g->data.bpp, &g->data.line_length, &g->data.endian);
	mlx_hook(g->data.mlx_win, 33, 1L << 17, exit_game, g);
	mlx_hook(g->data.mlx_win, 2, 1L << 0, key_press, g);
	mlx_loop_hook(g->data.mlx_ptr, start_raycasting, g);
	mlx_hook(g->data.mlx_win, 3, 1L << 1, key_release, g);
	mlx_loop(g->data.mlx_ptr);
	return (0);
}
