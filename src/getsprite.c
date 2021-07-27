/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getsprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:33:01 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:33:03 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*sprite_texture(const char *str, t_game *g)
{
	int	i;

	i = 1;
	while (white_space(str[i]) && str[i])
		i++;
	if (str[i] == '.' && str[i + 1] == '/')
		g->map->sprite = ft_substr(str, i, ft_strlen(str) - i);
	return (g->map->sprite);
}

int	getsprite(const char *str, t_game *g)
{
	char	*s;
	int		i;

	i = 0;
	if (!white_space(str[1]))
		get_err("Error\nneed space after S", g);
	if (g->map->sprite)
		get_err("Error\nduplicate sprite", g);
	else
		s = sprite_texture(str, g);
	if (!s)
		return (1);
	while (s[i++])
		if (white_space(s[i]))
			return (1);
	return (0);
}
