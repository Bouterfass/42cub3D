/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:36:20 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:36:24 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_in_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*trimstr(const char *s1, const char *set)
{
	char	*new_s1;
	int		deb;
	int		fin;
	int		len;

	if (!s1 || !set)
		return (NULL);
	deb = 0;
	fin = ft_strlen(s1) - 1;
	while (is_in_set(s1[deb], set) && s1[deb])
		deb++;
	if (!s1[deb])
		return (ft_strdup(s1 + deb));
	while (is_in_set(s1[fin], set))
		fin--;
	len = (fin - deb) + 1;
	new_s1 = ft_substr(s1, deb, len);
	return (new_s1);
}

int	white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\v'
		|| c == '\r')
		return (1);
	return (0);
}

int	empty_line(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (white_space(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
