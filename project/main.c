/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:43:17 by femaury           #+#    #+#             */
/*   Updated: 2018/04/25 13:09:44 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

int		main(int ac, char **av)
{
	int			i;
	int			tetris;
	char		**res;
	t_tetris	ttab[3];

	i = 0;
	tetris = 0;
	ttab[0].posy[0] = 0;
	ttab[0].posy[1] = 1;
	ttab[0].posy[2] = 1;
	ttab[0].posx[0] = 1;
	ttab[0].posx[1] = 1;
	ttab[0].posx[2] = 2;
	ttab[1].posy[0] = 0;
	ttab[1].posy[1] = 1;
	ttab[1].posy[2] = 1;
	ttab[1].posx[0] = 1;
	ttab[1].posx[1] = 0;
	ttab[1].posx[2] = 1;
	ttab[2].posy[0] = 0;
	ttab[2].posy[1] = 0;
	ttab[2].posy[2] = 0;
	ttab[2].posx[0] = 1;
	ttab[2].posx[1] = 2;
	ttab[2].posx[2] = 3;
	if (ac != 2)
		ft_putstr("USAGE...\n");
	else if (!(tetris = ft_readfile(av[1])))
		ft_putstr(RED"Error. File not valid.\n"EOC);
	else
	{
		ft_putstr(GREEN"File is valid.\n"EOC"Tetriminos found: ");
		ft_putnbr(tetris);
		ft_putchar('\n');
	}
	if (!(res = ft_fillmap(ttab, ft_createmap(5), 5)))
		return (1);
	ft_putchar('\n');
	while (i < 5)
		ft_putstrnl(res[i++]);
	return (0);
}
