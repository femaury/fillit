/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:32:20 by femaury           #+#    #+#             */
/*   Updated: 2018/04/26 19:28:46 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

char	**ft_readfile(char *s)
{
	int		i;
	int		fd;
	char	**buf;

	i = 0;
	if (!(buf = (char **)malloc(sizeof(char *) * 27)))
		return (NULL);
	while (i < 27)
		if (!(buf[i++] = (char *)ft_memalloc(22)))
			return (NULL);
	if ((fd = open(s, O_RDONLY)) == -1)
		return (NULL);
	i = 0;
	while (read(fd, buf[i], 21) > 0)
		i++;
	if (i == 0)
		return (NULL);
	if (buf[i - 1][20] || !buf[0][19])
		return (NULL);
	close(fd);
	return (buf);
}
