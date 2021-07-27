/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:26:19 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:26:22 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub3d(char *file, t_game *g)
{
	int	i;

	i = ft_strlen(file);
	while (file[i] != '.')
	{
		i--;
		if (i == 0)
			get_err("File Error: no file detected", g);
	}
	if (file[i + 1] == 'c' && file[i + 2] == 'u'
		&& file[i + 3] == 'b' && file[i + 4] == '\0')
		retrieve_info(g);
	else
		get_err("File Error: must be '.cub' file", g);
	return (0);
}
