/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manhattan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:07:22 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/20 18:07:23 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			manh_next(t_fl *fl, int i)
{
	int		m;
	int		p;
	int		p1;

	m = i;
	i++;
	while (i < fl->xy && fl->map[i] != -2)
		i++;
	if (i >= fl->xy)
		return (0);
	else if (fl->map[i] == -2)
		p = FT_ABS(i / fl->y - m / fl->y) + FT_ABS(i % fl->y - m % fl->y);
	i++;
	while (i < fl->xy)
	{
		if (fl->map[i] == -2)
		{
			p1 = FT_ABS(i / fl->y - m / fl->y) + FT_ABS(i % fl->y - m % fl->y);
			p = FT_MIN(p, p1);
		}
		if ((i / fl->y - m / fl->y) >= p)
			break ;
		i++;
	}
	return (p);
}

int			manh_prev(t_fl *fl, int i)
{
	int		m;
	int		p;
	int		p1;

	m = i;
	i--;
	while (i >= 0 && fl->map[i] != -2)
		i--;
	if (i < 0)
		return (0);
	else if (fl->map[i] == -2)
		p = FT_ABS(i / fl->y - m / fl->y) + FT_ABS(i % fl->y - m % fl->y);
	i--;
	while (i >= 0)
	{
		if (fl->map[i] == -2)
		{
			p1 = FT_ABS(i / fl->y - m / fl->y) + FT_ABS(i % fl->y - m % fl->y);
			p = FT_MIN(p, p1);
		}
		if ((m / fl->y - i / fl->y) >= p)
			break ;
		i--;
	}
	return (p);
}

int			manhattan(t_fl *fl)
{
	int		i;
	int		next;
	int		prev;
	int		*test;

	test = fl->map;
	i = 0;
	while (i < fl->xy)
	{
		if (!fl->map[i])
		{
			next = manh_next(fl, i);
			prev = manh_prev(fl, i);
			if (next && prev)
				fl->map[i] = FT_MIN(next, prev);
			else
				fl->map[i] = FT_MAX(next, prev);
		}
		i++;
	}
	return (0);
}
