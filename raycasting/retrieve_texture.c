/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:42:59 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:43:12 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	retrieve_text_addr(t_game *g)
{
	g->text[0].addr = (int *)mlx_get_data_addr(g->text[0].img,
			&g->text[0].bpp, &g->text[0].line_length, &g->text[0].endian);
	g->text[1].addr = (int *)mlx_get_data_addr(g->text[1].img,
			&g->text[1].bpp, &g->text[1].line_length, &g->text[1].endian);
	g->text[2].addr = (int *)mlx_get_data_addr(g->text[2].img,
			&g->text[2].bpp, &g->text[2].line_length, &g->text[2].endian);
	g->text[3].addr = (int *)mlx_get_data_addr(g->text[3].img,
			&g->text[3].bpp, &g->text[3].line_length, &g->text[3].endian);
	g->text[4].addr = (int *)mlx_get_data_addr(g->text[4].img,
			&g->text[4].bpp, &g->text[4].line_length, &g->text[4].endian);
}

void	retrieve_texturebis(t_game *g)
{
	g->text[3].img = mlx_xpm_file_to_image(g->data.mlx_ptr,
			g->map->eatext, &(g->text[3].width),
			&(g->text[3].height));
	if (!(g->text[3].img))
		get_err("Error\ncannot get texture", g);
	g->text[4].img = mlx_xpm_file_to_image(g->data.mlx_ptr,
			g->map->sprite, &(g->text[4].width),
			&(g->text[4].height));
	if (!(g->text[4].img))
		get_err("Error\ncannot get texture", g);
}

void	retrieve_texture(t_game *g)
{
	g->text[0].img = mlx_xpm_file_to_image(g->data.mlx_ptr,
			g->map->notext, &(g->text[0].width),
			&(g->text[0].height));
	if (!(g->text[0].img))
		get_err("Error\ncannot get texture", g);
	g->text[1].img = mlx_xpm_file_to_image(g->data.mlx_ptr,
			g->map->sotext, &(g->text[1].width),
			&(g->text[1].height));
	if (!(g->text[1].img))
		get_err("Error\ncannot get texture", g);
	g->text[2].img = mlx_xpm_file_to_image(g->data.mlx_ptr,
			g->map->wetext, &(g->text[2].width),
			&(g->text[2].height));
	if (!(g->text[2].img))
		get_err("Error\ncannot get texture", g);
	retrieve_texturebis(g);
	retrieve_text_addr(g);
}
