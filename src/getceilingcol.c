/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getceilingcol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:30:13 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:30:16 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_closest(const char *s, int nb)
{
	int	i;

	i = nb - 1;
	while (i > 0 && white_space(s[i]))
		i--;
	if (s[i] == ',' || s[i] == 'C' || s[i] == 'F')
	{
		return (1);
	}
	i = nb + 1;
	 while (s[i] && white_space(s[i]))
		i++;
	if (s[i] == ',' || i == ft_strlen(s))
		return (1);
	return (0);
}

int	wrong_char(const char *s)
{
	int	i;
	int	coma;

	i = 0;
	coma = 0;
	while (s[++i])
	{
		if (!is_digit(s[i]) && s[i] != ','
			&& !white_space(s[i]))
			return (1);
		if (s[i] == ',')
			coma++;
		if (is_digit(s[i]))
			if (white_space(s[i + 1]) || white_space(s[i - 1]))
				if (get_closest(s, i) == 0)
					return (1);
	}
	if (coma != 2)
		return (1);
	return (0);
}

int	get_cnumber(const char *str, int i, int j, t_game *g)
{
	str = str + i;
	g->map->ceilingcol[j] = 0;
	while (*str == ',' || *str == ' ')
	{
		str++;
		i++;
	}
	if (*str == '-')
		get_err("Error\nnegative color", g);
	while (is_digit(*str))
	{
		g->map->ceilingcol[j] = g->map->ceilingcol[j] * 10 + *str - 48;
		str++;
		i++;
	}
	return (i);
}

int	getceilingcol(const char *str, t_game *g)
{
	const char	*s;
	int			i;

	i = 0;
	if (count_numbers(str) > 3)
		get_err("Error\ntoo much colors for the sky", g);
	if (count_numbers(str) < 3)
		get_err("Error\na sky color is missing", g);
	if (wrong_char(str) == 1)
		get_err("Error\nwrong character in ceiling color", g);
	s = str + 1;
	if (!s)
		return (1);
	i = get_cnumber(s, i, 0, g);
	i = get_cnumber(s, i, 1, g);
	i = get_cnumber(s, i, 2, g);
	if ((g->map->ceilingcol[0] < 0 || g->map->ceilingcol[0] > 255)
		|| (g->map->ceilingcol[1] < 0 || g->map->ceilingcol[1] > 255)
		|| (g->map->ceilingcol[2] < 0 || g->map->ceilingcol[2] > 255))
		get_err("Error\ncolor must be between 0 and 255", g);
	return (0);
}
