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

static int		check_c(int *ext, int map_i, int *m, int *mm)
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

int				check_i(t_fl *fl, int i, int j, int res)
{
	int		i_map;
	int		x;
	int		y;

	i += (j / fl->py) * fl->mpy + j % fl->py;
	if (((x = i / fl->mpy) < fl->px || x >= fl->x + fl->px) && !res)
		return (-1);
	else if (((y = i % fl->mpy) < fl->py || y >= fl->py + fl->y) && !res)
		return (-1);
	x -= fl->px;
	y -= fl->py;
	i_map = x * fl->y + y;
	if (res && i == -1)
		ft_putendl("0 0");
	else if (res)
	{
		ft_putnbr(x);
		ft_putchar(' ');
		ft_putnbr(y);
		ft_putchar('\n');
	}
	return (i_map);
}

int				check_coord(t_fl *fl, int i, int *place, int ext)
{
	int		j;
	int		m;
	int		mm;
	int		i_map;

	if (i / fl->mpy + fl->px >= fl->mpx || i % fl->mpy + fl->py >= fl->mpy)
		return (0);
	j = 0;
	m = 0;
	mm = 0;
	while (j < fl->pxy)
	{
		if (fl->piece[j])
		{
			if ((i_map = check_i(fl, i, j, 0)) < 0)
				return (0);
			if (!(check_c(&ext, fl->map[i_map], &m, &mm)))
				return (0);
		}
		j++;
	}
	if (ext != 0)
		return (0);
	*place = mm;
	return (m);
}

void			select_coordinates_a(t_fl *fl, int *i, int *crd, int *crd1)
{
	if ((crd1[1] = check_coord(fl, *i, (&crd1[2]), -1)))
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

void			select_coordinates(t_fl *fl)
{
	int		crd[3];
	int		crd1[3];
	int		i;
	int		end;

	i = 0;
	ft_bzero(&crd, sizeof(crd));
	ft_bzero(&crd1, sizeof(crd1));
	crd[0] = -1;
	end = (fl->x + fl->px) * fl->mpy;
	while ((i < end) && !crd[1])
	{
		if ((crd1[1] = check_coord(fl, i, (&crd1[2]), -1)))
		{
			crd[0] = i;
			crd[1] = crd1[1];
		}
		i++;
	}
	while (i < end)
		select_coordinates_a(fl, &i, crd, crd1);
	check_i(fl, crd[0], 0, 1);
}
