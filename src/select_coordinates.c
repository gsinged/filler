/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:46:49 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/20 21:46:51 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_coord(t_fl *fl, int i, int *place)
{
	int		j;
	int		m;
	int		ext;
	int		map_i;
	int		mm;

	if (((i / fl->y + fl->px) > fl->x) || ((i % fl->y + fl->py) > fl->y))
		return (0);
	j = 0;
	m = 0;
	mm = 0;
	ext = -1;
	while (j < fl->pxy)
	{
		if (fl->piece[j])
		{
			map_i = fl->map[i + (j / fl->py) * fl->y + j % fl->py];
			if (map_i == -2)
				return (0);
			else if (map_i == -1)
				ext++;
			else
			{
				if (!mm)
					mm = map_i;
				else if (mm > map_i)
					mm = map_i;
				m += map_i;
			}
		}
		j++;
	}
	if (ext != 0)
		return (0);
	*place = m;
	return (mm);
}

/*
int			choose_better(t_fl *fl, int *crd, int  crd1)
{
	return (0);
}
*/

int			select_coordinates(t_fl *fl)
{
	int		crd[3];
	int		crd1[3];
	int		i;

	i = 0;
	crd[0] = 0;
	crd[1] = 0;
	while (i < fl->xy && !crd[1])
	{
		if ((crd1[1] = check_coord(fl, i, (&crd1[2]))))
		{
			crd[0] = i;
			crd[1] = crd1[1];
		}
		i++;
	}
	while (i < fl->xy)
	{
		if ((crd1[1] = check_coord(fl, i, (&crd1[2]))))
		{
			if (crd[1] > crd1[1] || (crd[1] == crd1[1] && crd[2] > crd1[2]))
			{
				crd[0] = i;
				crd[1] = crd1[1];
				crd[2] = crd1[2];
			}
//			else if (crd[1] == crd1[1])
		}
		i++;
	}
		ft_putnbr(crd[0] / fl->y);
		ft_putchar(' ');
		ft_putnbr(crd[0] % fl->y);
		ft_putchar('\n');
	return (0);
}
