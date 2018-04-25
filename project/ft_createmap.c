/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:16:19 by femaury           #+#    #+#             */
/*   Updated: 2018/04/25 15:55:39 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

char	**ft_createmap(size_t size)
{
	unsigned int	i;
	char			**map;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = (char *)malloc(size + 1)))
			return (NULL);
		if (!ft_memset(map[i], '.', size))
			return (NULL);
		map[i][size] = '\0';
		i++;
	}
	if (!(map[size] = (char *)ft_memalloc(1)))
		return (NULL);
	return (map);
}
