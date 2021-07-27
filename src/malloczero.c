/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloczero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:35:06 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:35:11 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_bzero(void *block, size_t size)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = block;
	while (i < size)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*malloczero(size_t size)
{
	void	*dest;

	dest = malloc(size);
	if ((dest))
		ft_bzero(dest, size);
	return (dest);
}
