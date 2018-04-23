/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 20:03:22 by femaury           #+#    #+#             */
/*   Updated: 2018/04/23 19:37:33 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define MAX_FSIZE 548

int		ft_checkblock(char *s, int pos)
{
	int		blocks;
	int		links;
	int		rows;

	blocks = 0;
	links = 0;
	rows = 0;
	while (*s)
	{
		if (*s == '#')
		{
			if ((pos >= 0 && pos <= 3) || (pos >= 5 && pos <= 8) ||
				(pos >= 10 && pos <= 13))
			{
				if (s[pos + 1] == '#')
					links += 2;
				if (s[pos + 5] == '#')
					links += 2;
			}
			if (pos >= 15 && pos <= 17 && s[pos + 1] == '#')
				links += 2;
			if (pos == 5 || pos == 9 || pos == 14 || pos == 19 ||
					blocks == 3)
				return (1);
			blocks++;
		}
		if (row == 3 && pos == 19)
		{
			row = 0;
			pos = -1;
		}
		if (pos == (4 + 5 * row))
			row++;
		pos++;		
	}
}

int		ft_checkchars(char *s, int row, int pos, int bcount)
{
	while (*s)
	{
		if (*s == '\n' && row != 3)
		{
			if (pos != (4 + 5 * row++))
				return (1);
		}
		else if (row == 3 && pos == 19)
		{
			if (*s != '\n' || (*(s + 1) != '\n' && *(s + 1)))
				return (3);
			pos = -1;
			row = 0;
			s++;
		}
		pos++;
		s++;
	}
	return (0);
}

int		ft_checkstr(char *s)
{
	int		i;

	i = 0;
	while (s[i] && i <= 545)
	{
		printf("i = %d\n", i);
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
			return (1);
		i++;
	}
	if (i == 546)
		return (1);
	return (0);
}

int		ft_checktetri(char *s)
{
	int		row;
	int		pos;
	int		bcount;
	char	*sc;

	row = 0;
	pos = 0;
	bcount = 0;
	sc = s;
	if (ft_checkstr(sc))
		return (4);
	if (ft_checkblock(s))
		return (5);
	return (ft_checkchars(sc, row, pos, bcount));
}

int		ft_checkfile(char *s)
{
	int		fd;
	int		rd;
	char	*buf;

	buf = (char *)ft_memalloc((size_t)MAX_FSIZE + 1);
	if ((fd = open(s, O_RDONLY)) == -1)
		return (1);
	if ((rd = read(fd, buf, MAX_FSIZE)) == -1)
		return (1);
	buf[rd] = '\0';
	close(fd);
	return (ft_checktetri(buf));
}

int		main(int ac, char **av)
{
	int	erno;

	erno = 0;
	(void)ac;
	if ((erno = ft_checkfile(av[1])))
		printf("Error %d.\n", erno);
	else
		printf("Success!\n");
	return (0);
}
