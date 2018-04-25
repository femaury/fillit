/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:35:44 by femaury           #+#    #+#             */
/*   Updated: 2018/04/25 13:02:20 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

static char	**ft_fillmapext(t_tetris ttab[], char **map, int i[4], size_t size)
{
	if (map[i[1]][i[2]] == '.' && i[1] < (int)size - 1)
	{
		while (i[3] < 3 && MAP_FIND(i[0], i[3]) == '.')
			i[3]++;
		if (i[3] == 3)
		{
			map[i[1]][i[2]] = 'A' + i[0];
			i[3] = -1;
			while (++i[3] < 3)
				MAP_FIND(i[0], i[3]) = 'A' + i[0];
		}
	}
	if (i[2]++ - 1 == (int)size)
	{
		i[1] += 1;
		i[2] = 0;
	}
	return (map);
}

char		**ft_fillmap(t_tetris ttab[], char **map, size_t size)
{
	int		i[4];

	i[0] = 0;
	i[2] = 0;
	while (i[0] < 3)
	{
		i[1] = 0;
		while (i[1] < (int)size)
		{
			i[3] = 0;
			while (map[i[1]][i[2]] != '.' && map[i[1]][i[2]] != 0)
				i[2]++;
			map = ft_fillmapext(ttab, map, i, size);
			if (i[3] == 3)
				break ;
		}
		if (i[3] != 3)
			return (NULL);
		i[0]++;
	}
	return (map);
}
