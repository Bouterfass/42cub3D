/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:24:07 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:24:11 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_text(char *s, t_game *g)
{
	char	*str;

	str = trimstr(s, " \t\v\r\f");
	if (str[0] == 'N' && str[1] == 'O')
		g->map->countnot++;
	if (str[0] == 'S' && str[1] == 'O')
		g->map->countsot++;
	if (str[0] == 'W' && str[1] == 'E')
		g->map->countwet++;
	if (str[0] == 'E' && str[1] == 'A')
		g->map->counteat++;
	if (str[0] == 'S' && white_space(str[1]))
		g->map->countst++;
	if (str[0] == 'F' && white_space(str[1]))
		g->map->countfc++;
	if (str[0] == 'C' && white_space(str[1]))
		g->map->countcc++;
	if (str[0] == 'R' && white_space(str[1]))
		g->map->countres++;
	free(str);
}

void	count_text(t_game *g)
{
	int		endl;
	char	*line;

	endl = 1;
	line = NULL;
	g->map->fd = open(g->map->file, O_RDONLY);
	if (g->map->fd == -1)
		get_err("Error\ncannot open file", g);
	while (endl > 0)
	{
		endl = get_next_line(g->map->fd, &line);
		get_text(line, g);
		free(line);
	}
	close(g->map->fd);
}
