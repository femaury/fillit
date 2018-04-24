/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:32:20 by femaury           #+#    #+#             */
/*   Updated: 2018/04/24 14:02:32 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/libft.h"

int		ft_checkfile(char **s);

int		ft_readfile(char *s)
{
	int		i;
	int		fd;
	char	**buf;

	i = 0;
	if (!(buf = (char **)malloc(sizeof(char *) * 27)))
		return (1);
	while (i < 27)
		if (!(buf[i++] = (char *)ft_memalloc(22)))
			return (1);
	if ((fd = open(s, O_RDONLY)) == -1)
		return (1);
	i = 0;
	while (read(fd, buf[i], 21) > 0)
		i++;
	if (buf[25][20] || !buf[0][19])
		return (1);
	close(fd);
	return (ft_checkfile(buf));
}

int		main(int ac, char **av)
{
	int		erno;

	erno = 0;
	if (ac != 2 || (erno = ft_readfile(av[1])))
		printf("\x1B[31mError %d while reading file.\n\033[0m", erno);
	else
		printf("\x1B[32mFile read and stored.\n\033[0m");
	return (0);
}
