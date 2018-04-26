/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:06:20 by femaury           #+#    #+#             */
/*   Updated: 2018/04/26 18:23:14 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

int		ft_checkblocks(char *s)
{
	int		i;
	int		links;

	i = 0;
	links = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if ((i >= 0 && i <= 3) || (i >= 5 && i <= 8) ||
					(i >= 10 && i <= 13))
			{
				if (s[i + 1] == '#')
					links += 2;
				if (s[i + 5] == '#')
					links += 2;
			}
			if (i >= 15 && i <= 17 && s[i + 1] == '#')
				links += 2;
		}
		i++;
	}
	return (links != 6 && links != 8) ? (1) : (0);
}

int		ft_checkfile(char **s)
{
	int		i;
	int		j;
	int		blocks;

	i = 0;
	while (s[i][0])
	{
		j = 0;
		blocks = 0;
		while (s[i][j])
		{
			if (s[i][j] != '.' && s[i][j] != '#' && s[i][j] != '\n')
				return (0);
			if ((s[i][j] == '\n' && N_DPOS(j)) ||
					(s[i][j] != '\n' && N_EPOS(j)))
				return (0);
			if (s[i][j++] == '#')
				if (blocks++ == 4)
					return (0);
		}
		if (blocks != 4 || ft_checkblocks(s[i]))
			return (0);
		i++;
	}
	return (i);
}
