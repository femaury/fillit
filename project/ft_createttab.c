/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createttab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:20:04 by badhont           #+#    #+#             */
/*   Updated: 2018/04/26 18:37:24 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

static t_tetris	*ft_fillttab(char **s, t_tetris *ttab, int i)
{
	int		j;
	int		tag;
	int		spot;

	j = 0;
	spot = 0;
	while (s[i][j] && s[i][j] != '#')
	j++;
	tag = j++;
	while (s[i][j])
	{
	while (s[i][j] != '#')
		j++;
	ttab[i].posy[spot] = (j / 5) - (tag / 5);
	ttab[i].posx[spot] = (j % 5) - (tag % 5);
	spot++;
	j++;
	}
	return (ttab);
}

t_tetris	*ft_createttab(char **s, int nb)
{
	int		i;

	i = 0;
	t_tetris    *ttab;
	if (!(ttab = (t_tetris *)malloc(sizeof(t_tetris) * nb)))
		return (NULL);
	while (i < nb)
	{
		ft_fillttab(s, ttab, i);
		i++;
	}
	return (ttab);
}
