/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfloorcol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:30:46 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:30:50 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	has_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (white_space(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	get_number(const char *str, int i, int j, t_game *g)
{
	str = str + i;
	g->map->floorcol[j] = 0;
	while (*str == ',' || *str == ' ')
	{
		str++;
		i++;
	}
	if (*str == '-')
		get_err("Error\nnegative color", g);
	while (is_digit(*str))
	{
		g->map->floorcol[j] = g->map->floorcol[j] * 10 + *str - 48;
		str++;
		i++;
	}
	return (i);
}

int	count_numbers(const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (is_digit(str[i]))
		{
			count++;
			while (is_digit(str[i]))
				i++;
		}
		else
			i++;
	}
	return (count);
}

int	getfloorcol(const char *str, t_game *g)
{
	const char	*s;
	int			i;

	i = 0;
	if (count_numbers(str) > 3)
		get_err("Error\ntoo much floor colors", g);
	if (count_numbers(str) < 3)
		get_err("Error\na floor color is missing", g);
	if (wrong_char(str))
		get_err("Error\nwrong character in floor color", g);
	s = str + 1;
	if (!s)
		return (1);
	i = get_number(s, i, 0, g);
	i = get_number(s, i, 1, g);
	i = get_number(s, i, 2, g);
	if ((g->map->floorcol[0] < 0 || g->map->floorcol[0] > 255)
		|| (g->map->floorcol[1] < 0 || g->map->floorcol[1] > 255)
		|| (g->map->floorcol[2] < 0 || g->map->floorcol[2] > 255))
		get_err("Error\ncolor must be between 0 and 255", g);
	return (0);
}
