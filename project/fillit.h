/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:55:03 by femaury           #+#    #+#             */
/*   Updated: 2018/05/02 12:58:47 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdio.h>

# define N_DPOS(n) (n != 4 && n != 9 && n != 14 && n != 19 && n != 20)
# define N_EPOS(n) (n == 4 || n == 9 || n == 14 || n == 19)
# define MAP_FIND(a, b) map[i[1] + ttab[a].posy[b]][i[2] + ttab[a].posx[b]]

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define EOC "\033[0m"

typedef struct	s_tetris
{
	int		posx[3];
	int		posy[3];
	int		startx;
	int		starty;
}				t_tetris;

t_tetris		*ft_createttab(char **s, int nb);
void			ft_putcolor(char const *s);
char			**ft_createmap(size_t size);
char			**ft_fillmap(t_tetris ttab[], char **map, size_t size, int nb);
char			**ft_readfile(char *s);
int				ft_checkfile(char **s);

#endif
