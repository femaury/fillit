/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:43:17 by femaury           #+#    #+#             */
/*   Updated: 2018/04/30 16:46:41 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

int		ft_fillit(char *file, int tetris)
{
	int			i;
	int			size;
	char		**res;
	t_tetris	*ttab;

	i = 0;
	if (!(ttab = ft_createttab(ft_readfile(file), tetris)))
		return (1);
	size = (ft_sqrt(tetris) * 2);
	while (!(res = ft_fillmap(ttab, ft_createmap(size), size, tetris)))
		size++;
	while (i < size)
		ft_putendl(res[i++]);
	return (0);
}

int		main(int ac, char **av)
{
	int			tetris;
	char		**read;

	tetris = 0;
	if (ac != 2)
		ft_putendl("usage: ./fillit target_file");
	else if (!(read = ft_readfile(av[1])))
		ft_putendl("error");
	else if (!(tetris = ft_checkfile(read)))
		ft_putendl("error");
	else
	{
		if (ft_fillit(av[1], tetris))
			return (1);
	}
	return (0);
}
