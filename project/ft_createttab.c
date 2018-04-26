/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createttab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:20:04 by badhont           #+#    #+#             */
/*   Updated: 2018/04/26 15:24:29 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

t_tetris    *ft_createttab(char **s, int nb)
{
    int         i;
    int         j;
    int         tag;
    int         spot;
    t_tetris    *ttab;

    i = 0;
    if (!(ttab = (t_tetris *)malloc(sizeof(t_tetris) * nb)))
        return (NULL);
    while (i < nb)
    {
        spot = 0;
        j = 0;
        while (s[i][j] && s[i][j] != '#')
            j++;
        tag = j++;
        while (s[i][j])
        {
            while (s[i][j] && s[i][j] != '#')
                j++;
			ttab[i].posy[spot] = (j / 5) - (tag / 5);
            ttab[i].posx[spot] = (j % 5) - (tag % 5);
            spot++;
            j++;
			if (spot == 3)
				break ;
        }
        i++;
    }
    return (ttab);
}
