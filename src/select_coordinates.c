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

int			check_coord(t_fl *fl, int i)
{
	int		j;
	int		m;
	int		ext;
	int		map;

	if (((i / fl->y + fl->px) > fl->x) || ((i % fl->y + fl->py) > fl->y))
		return (0);
	j = 0;
	m = 0;
	ext = -1;
	while (j < fl->pxy)
	{
		if (fl->piece[j])
		{
			map = fl->map[i + (j / fl->py) * fl->y + j % fl->py];
			if (fl->map[i + (j / fl->py) * fl->y + j % fl->py] == -2)
				return (0);
			else if (fl->map[i + (j / fl->py) * fl->y + j % fl->py] == -1)
				ext++;
			else
				m += fl->map[i + (j / fl->py) * fl->y + j % fl->py];
		}
		j++;
	}
	if (ext != 0)
		return (0);
	return (m);
}

/*
int			choose_better(t_fl *fl, int *crd, int  crd1)
{
	return (0);
}
*/

int			select_coordinates(t_fl *fl)
{
	int		crd[2];
	int		crd1[2];
	int		i;

	i = 0;
	crd[1] = 0;
	while (i < fl->xy && !crd[1])
	{
		if ((crd1[1] = check_coord(fl, i)))
		{
			crd[0] = i;
			crd[1] = crd1[1];
		}
		i++;
	}
	while (i < fl->xy)
	{
		if ((crd1[1] = check_coord(fl, i)))
		{
			if (crd[1] > crd1[1])
			{
				crd[0] = i;
				crd[1] = crd1[1];
			}
//			else if (crd[1] == crd1[1])
		}
		i++;
	}
	if (crd[1])
		ft_printf("%d %d\n", crd[0] / fl->y, crd[0] % fl->y);
	return (0);
}

