/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnotext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:32:16 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:32:17 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*no_texture(const char *str, t_game *g)
{
	int	i;

	i = 2;
	while (white_space(str[i]) && str[i])
		i++;
	if (str[i] == '.' && str[i + 1] == '/')
		g->map->notext = ft_substr(str, i, ft_strlen(str) - i);
	return (g->map->notext);
}

int	getnotext(const char *str, t_game *g)
{
	char	*s;
	int		i;

	i = 0;
	if (!white_space(str[2]))
		get_err("Error\nneed space after NO", g);
	if (g->map->notext)
		get_err("Error\ntoo much NO textures", g);
	s = no_texture(str, g);
	if (!s)
		return (1);
	while (s[i])
	{
		if (white_space(s[i]))
			return (1);
		i++;
	}
	return (0);
}
