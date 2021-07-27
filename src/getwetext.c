/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getwetext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:33:12 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:33:16 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*we_texture(const char *str, t_game *g)
{
	int	i;

	i = 2;
	while (white_space(str[i]) && str[i])
		i++;
	if (str[i] == '.' && str[i + 1] == '/')
		g->map->wetext = ft_substr(str, i, ft_strlen(str) - i);
	return (g->map->wetext);
}

int	getwetext(const char *str, t_game *g)
{
	char	*s;
	int		i;

	i = 0;
	if (!white_space(str[2]))
		get_err("Error\nneed space after WE", g);
	if (g->map->wetext)
		get_err("Error\ntoo much WE texture", g);
	s = we_texture(str, g);
	if (!s)
		return (1);
	while (s[i++])
		if (white_space(s[i]))
			return (1);
	return (0);
}
