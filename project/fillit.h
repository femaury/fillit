/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:55:03 by femaury           #+#    #+#             */
/*   Updated: 2018/04/24 15:32:33 by femaury          ###   ########.fr       */
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

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define EOC "\033[0m"

int		ft_checkfile(char **s);

#endif
