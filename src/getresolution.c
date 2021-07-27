/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getresolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:32:26 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:32:31 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	wrong_res(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_digit(str[i]) && str[i] != 'R'
			&& !white_space(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	getresolution(const char *str, t_game *g)
{
	int	i;

	i = 1;
	if (wrong_res(str) == 1)
		get_err("Error\nbad character in resolution line", g);
	i = ft_atoix(str, i, g);
	i = ft_atoiy(str, i, g);
	if (str[i] != '\0')
	{
		while (str[i])
		{
			if (!white_space(str[i]))
				get_err("Error\ntoo much arguments for resolution", g);
			i++;
		}
	}
	if (g->map->rx == 0 || g->map->ry == 0)
		get_err("Error\nresolution cannot be equal to 0", g);
	return (0);
}
