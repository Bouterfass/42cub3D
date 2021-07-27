/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:28:15 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:28:17 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*ft_memcpy(void *to, void *from, size_t size)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	if (!to && !from)
		return (0);
	s = (unsigned char *)from;
	d = (unsigned char *)to;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
