/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:31:28 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:31:36 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_mapline(const char *str)
{
	int	i;

	i = 0;
	if (empty_line(str) == 1 || !str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' '
			&& str[i] != '2' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E'
			&& str[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int	fill_line(t_mapinfo *map, char *line, int len, int i)
{
	int	j;

	j = 0;
	map->map[i] = NULL;
	map->map[i] = (char *)malloc((sizeof(char) * map->mapx));
	if (!(map->map[i]))
		return (0);
	while (j < map->mapx)
	{
		if (j < len)
		{
			if (line[j] == ' ')
				map->map[i][j] = '1';
			else
				map->map[i][j] = line[j];
		}
		else
			map->map[i][j] = '1';
		if (len == map->mapx)
			if (line[map->mapx - 1] == '0')
				map->map[i][len] = '1';
		j++;
	}
}

int	fill_map(int x, int y, t_mapinfo *m)
{
	char	*line;
	int		i;
	int		endl;

	endl = 1;
	i = 0;
	line = NULL;
	m->fd = open(m->file, O_RDONLY);
	m->map = (char **)malloc((sizeof(char *) * y) + 1);
	if (!(m->map))
		return (0);
	while (endl > 0 || i < y)
	{
		endl = get_next_line(m->fd, &line);
		if (is_mapline(line))
		{
			fill_line(m, line, ft_strlen(line), i);
			i++;
		}
		free(line);
	}
	close(m->fd);
}

void	getmapsize(const char *l, t_game *g)
{
	char	*line;
	int		endl;

	endl = 1;
	line = NULL;
	if (is_mapline(l))
		if (ft_strlen(l) > g->map->mapx)
			g->map->mapx = ft_strlen(l);
	while (endl > 0)
	{
		endl = get_next_line(g->map->fd, &line);
		if (is_mapline(line))
		{
			if (ft_strlen(line) > g->map->mapx)
				g->map->mapx = ft_strlen(line);
			g->map->mapy++;
		}
		free(line);
	}
	if (g->map->mapy == 1 || g->map->mapx == 1)
		get_err("Error\nthe map is not big enough", g);
	fill_map(g->map->mapx, g->map->mapy, g->map);
}

void	getinfo(char *str, t_game *g)
{
	if (str[0] == 'R')
		getresolution(str, g);
	else if (str[0] == 'N' && str[1] == 'O')
		getnotext(str, g);
	else if (str[0] == 'S' && str[1] == 'O')
		getsotext(str, g);
	else if (str[0] == 'W' && str[1] == 'E')
		getwetext(str, g);
	else if (str[0] == 'E' && str[1] == 'A')
		geteatext(str, g);
	else if (str[0] == 'S' && white_space(str[1]))
		getsprite(str, g);
	else if (str[0] == 'F' && white_space(str[1]))
		getfloorcol(str, g);
	else if (str[0] == 'C' && white_space(str[1]))
		getceilingcol(str, g);
	else if (!empty_line(str))
		get_err("Error\nundefined line", g);
	free(str);
}
