/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getsotext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:32:47 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:32:51 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*so_texture(const char *str, t_game *g)
{
	int	i;

	i = 2;
	while (white_space(str[i]) && str[i])
		i++;
	if (str[i] == '.' && str[i + 1] == '/')
		g->map->sotext = ft_substr(str, i, ft_strlen(str) - i);
	return (g->map->sotext);
}

void	getsotext(const char *str, t_game *g)
{
	char	*s;
	int		i;

	i = 0;
	if (!white_space(str[2]))
		get_err("Error\nneed space after SO", g);
	if (g->map->sotext)
		get_err("Error\ntoo much SO textures", g);
	s = so_texture(str, g);
	if (!s)
		get_err("Error\nno texture found", g);
	while (s[i++])
		if (white_space(s[i]))
			get_err("Error\nspace in texture", g);
}
