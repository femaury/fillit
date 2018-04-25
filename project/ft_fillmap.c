/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:35:44 by femaury           #+#    #+#             */
/*   Updated: 2018/04/25 17:55:30 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

static char	**ft_delprev(t_tetris ttab[], char **map, int i[6])
{
	int		x;

	x = 0;
	map[i[4 + i[0]]][i[30 + i[0]]] = '.';
	while (x < 3)
	{
		map[i[4 + i[0]] + ttab[i[0]].posy[x]][i[30 + i[0]] + ttab[i[0]].posx[x]] = '.';
		x++;
	}
	return (map);
}

static char	**ft_fillmapext(t_tetris ttab[], char **map, int i[6], size_t size)
{
	if (map[i[1]][i[2]] == '.')
	{
		while (i[3] < 3 && MAP_FIND(i[0], i[3]) == '.')
			i[3]++;
		if (i[3] == 3)
		{
			i[4 + i[0]] = i[1];
			i[30 + i[0]] = i[2];
			map[i[1]][i[2]] = 'A' + i[0];
			i[3] = -1;
			while (++i[3] < 3)
				MAP_FIND(i[0], i[3]) = 'A' + i[0];
		}
	}
	if (i[2]++ >= (int)size)
	{
		i[1]++;
		i[2] = 0;
	}
	return (map);
}

char		**ft_fillmap(t_tetris ttab[], char **map, size_t size, int nb)
{
	int		i[55];
	int		j;
	int		x;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	j = 0;
	x = 0;
	while (i[0] < nb)
	{
		if (i[0] == 0 && i[2] == (int)size && i[1] == (int)size)
			return (NULL);
		while (i[1] < (int)size)
		{
			i[3] = 0;
			while (map[i[1]][i[2]] != '.' && map[i[1]][i[2]])
				i[2]++;
			map = ft_fillmapext(ttab, map, i, size);
			if (i[3] == 3)
			{
				i[1] = 0;
				i[2] = 0;
				break ;
			}
		}
		if (i[3] != 3 && j < 15)
		{
			i[0]--;
			map = ft_delprev(ttab, map, i);
			i[0]--;
			i[1] = (i[0] > -1 ? i[4 + i[0] + 1] : i[4]);
			i[2] = (i[0] > -1 ? i[30 + i[0] + 1] : i[30]) + 1;
			if (i[2] >= (int)size)
			{
				i[2] = 0;
				i[1]++; 
			}
		}
		i[0]++;
		j++;
	}
	return (map);
}
