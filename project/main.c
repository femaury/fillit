/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:43:17 by femaury           #+#    #+#             */
/*   Updated: 2018/04/26 17:42:32 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

int		main(int ac, char **av)
{
	int			i;
	int			j;
	int			tetris;
	char		**res;
	t_tetris	*ttab;

	i = 0;
	tetris = 0;
	if (ac != 2)
		ft_putstr("USAGE...\n");
	else if (!(tetris = ft_checkfile(ft_readfile(av[1]))))
		ft_putstr(RED"Error. File is not valid..\n"EOC);
	else
	{
		ft_putstr(GREEN"File is valid.\n"EOC"Tetriminos found: ");
		ft_putnbr(tetris);
		ft_putchar('\n');
	}
	if (!(ttab = ft_createttab(ft_readfile(av[1]), tetris)))
		return (1);
	j = (ft_sqrt(tetris) * 2);
	while (!(res = ft_fillmap(ttab, ft_createmap(j), j, tetris)))
		j++;
	ft_putchar('\n');
	while (i < j)
	{
		ft_putcolor(res[i++]);
		ft_putchar('\n');
	}
	return (0);
}
