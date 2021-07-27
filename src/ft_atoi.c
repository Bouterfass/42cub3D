/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:27:13 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:27:16 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_atoix(const char *str, int i, t_game *g)
{
	int	res;

	res = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == ',' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > 10000000)
			break ;
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	g->map->rx = res;
	return (i);
}

int	ft_atoiy(const char *str, int i, t_game *g)
{
	int	res;

	res = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == ',' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > 10000000)
			break ;
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	g->map->ry = res;
	return (i);
}
