/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:34:43 by femaury           #+#    #+#             */
/*   Updated: 2018/04/26 13:20:48 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

void	ft_putcolor(char const *s)
{
	unsigned int	i;
	int				x;

	i = 0;
	while (s[i])
	{
		if (ft_isalpha(s[i]))
		{
			x = (s[i] - '@');
			if (x > 6)
				x -= 6;
			if (x == 1)
				ft_putstr(RED);
			else if (x == 2)
				ft_putstr(GREEN);
			else if (x == 3)
				ft_putstr(YELLOW);	
			else if (x == 4)
				ft_putstr(BLUE);
			else if (x == 5)
				ft_putstr(MAGENTA);
			else if (x == 6)
				ft_putstr(CYAN);
		}
		ft_putchar(s[i++]);
		ft_putstr(EOC);
	}
}
