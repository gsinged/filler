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

static int	check_coord_a(int *ext, int map_i, int *m, int *mm)
{

		if (map_i == -2)
			return (0);
		else if (map_i == -1)
			(*ext)++;
		else
		{
			if (!*mm)
				*mm = map_i;
			else if (*mm > map_i)
				*mm = map_i;
			*m += map_i;
		}

	return (1);
}

int			check_coord(t_fl *fl, int i, int *place)
{
	int		j;
	int		m;
	int		mm;
	int		ext;

	if (((i / fl->y + fl->px) > fl->x) || ((i % fl->y + fl->py) > fl->y))
		return (0);
	j = 0;
	m = 0;
	mm = 0;
	ext = -1;
	while (j < fl->pxy)
	{
		if (fl->piece[j])
			if (!check_coord_a(&ext, fl->map[i + (j / fl->py) * fl->y + j % fl->py], &m, &mm))
				return (0);
		j++;
	}
	if (ext != 0)
		return (0);
	*place = m;
	return (mm);
}

void			select_coordinates_a(t_fl *fl, int *i, int *crd, int *crd1)
{
	if ((crd1[1] = check_coord(fl, *i, (&crd1[2]))))
	{
		if (crd[1] > crd1[1] || (crd[1] == crd1[1] && crd[2] > crd1[2]))
		{
			crd[0] = *i;
			crd[1] = crd1[1];
			crd[2] = crd1[2];
		}
	}
	(*i)++;
}

int			select_coordinates(t_fl *fl)
{
	int crd[3];
	int crd1[3];
	int i;

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
		if (i == 146)
		{
//			test_print_map(fl);
			i = 146;
		}
		select_coordinates_a(fl, &i, crd, crd1);
	}
	test_print_map(fl);
	ft_putnbr(crd[0] / fl->y);
	ft_putchar(' ');
	ft_putnbr(crd[0] % fl->y);
	ft_putchar('\n');
	return (0);
}
