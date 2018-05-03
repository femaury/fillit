/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:35:44 by femaury           #+#    #+#             */
/*   Updated: 2018/05/03 17:36:34 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

static char	**ft_delprev(t_tetris ttab[], char **map, int i[5], size_t size)
{
	int		x;

	x = 0;
	i[0]--;
	map[ttab[i[0]].starty][ttab[i[0]].startx] = '.';
	while (x < 3)
	{
		map[ttab[i[0]].starty + ttab[i[0]].posy[x]][ttab[i[0]].startx +
			ttab[i[0]].posx[x]] = '.';
		x++;
	}
	i[0]--;
	i[1] = ttab[i[0] + 1].starty;
	i[2] = ttab[i[0] + 1].startx + 1;
	if (i[2] >= (int)size)
	{
		i[2] = 0;
		i[1]++;
	}
	i[4]--;
	return (map);
}

static char	**ft_fillmapext(t_tetris ttab[], char **map, int i[5], size_t size)
{
	i[3] = 0;
	while (map[i[1]][i[2]] != '.' && map[i[1]][i[2]])
		i[2]++;
	if (map[i[1]][i[2]] == '.')
	{
		while (i[3] < 3 && MAP_FIND(i[0], i[3]) == '.')
			i[3]++;
		if (i[3] == 3)
		{
			i[4]++;
			ttab[i[0]].starty = i[1];
			ttab[i[0]].startx = i[2];
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

static void	ft_check_sametetri(t_tetris ttab[], int i[5])
{
	int		x;
	int		z;

	z = 0;
	while (z < i[0] + 1)
	{
		x = 0;
		while (x < 3)
		{
			if (ttab[z].posy[x] != ttab[i[0] + 1].posy[x] ||
					ttab[z].posx[x] != ttab[i[0] + 1].posx[x])
				break ;
			x++;
		}
		if (x == 3)
		{
			i[1] = ttab[z].starty;
			i[2] = ttab[z].startx;
			return ;
		}
		z++;
	}
	i[1] = 0;
	i[2] = 0;
}

char		**ft_fillmap(t_tetris ttab[], char **map, size_t size, int nb)
{
	int		i[5];
	int		j;

	j = 0;
	while (j < 5)
		i[j++] = 0;
	while (i[0] < nb)
	{
		while (i[1] < (int)size)
		{
			map = ft_fillmapext(ttab, map, i, size);
			if (i[3] == 3)
			{
				ft_check_sametetri(ttab, i);
				break ;
			}
		}
		if (i[3] != 3 && i[4])
			map = ft_delprev(ttab, map, i, size);
		i[0]++;
	}
	return (i[4] ? (map) : (NULL));
}
