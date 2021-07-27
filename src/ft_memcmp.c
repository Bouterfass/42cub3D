/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:27:50 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:27:53 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_memcmp(const void *a1, const void *a2, size_t size)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)a1;
	str2 = (unsigned char *)a2;
	i = 0;
	if (!str1 && !str2)
		return (-1000);
	if (ft_strlen(str1) != ft_strlen(str2))
		return (-1000);
	if ((ft_strlen(str1) != size)
		|| ft_strlen(str2) != size)
		return (-1000);
	while (i < size)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((unsigned int)str1[i] - (unsigned int)str2[i]);
	}
	return (0);
}
