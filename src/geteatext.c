/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geteatext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:30:29 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:30:32 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ea_texture(const char *str, t_game *g)
{
	int			i;
	const char	*s;

	i = 2;
	s = str;
	while (white_space(str[i]) && str[i])
		i++;
	if (str[i] == '.' && str[i + 1] == '/')
		g->map->eatext = ft_substr(str, i, ft_strlen(str) - i);
	return (g->map->eatext);
}

int	geteatext(const char *str, t_game *g)
{
	char	*s;
	int		i;

	i = 0;
	if (!white_space(str[2]))
		get_err("Error\nneed space after EA", g);
	if (g->map->eatext)
		get_err("Error, too much EA textures", g);
	s = ea_texture(str, g);
	if (!s)
		return (1);
	while (s[i++])
		if (white_space(s[i]))
			return (1);
	return (0);
}
