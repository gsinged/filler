/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:13:07 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/18 19:13:11 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_fl_delete(t_fl **fl)
{
	if (fl && *fl)
	{
		if ((*fl)->map)
		{
			ft_bzero((*fl)->map, ((*fl)->size * sizeof(int)));
			free((*fl)->map);
		}
		ft_bzero(*fl, sizeof(t_fl));
		free((*fl));
		*fl = NULL;
	}
}

t_fl		*ft_error_tfl(void)
{
	exit(0);
}

int			ft_error(void)
{
	exit(0);
}








void		test_print_map(t_fl *fl)
{
	int		i;

	if (fl->map)
	{
		ft_putchar('\n');
		ft_printf("Plateau %d %d\n", fl->x, fl->y);
		i = 0;
		while (i < fl->xy)
		{
			if (fl->map[i] == 0)
				ft_putchar('.');
			else if (fl->map[i] == 1)
				ft_putchar((fl->pl == 1 ? 'O' : 'X'));
			else if (fl->map[i] == -1)
				ft_putchar(fl->pl == 1 ? 'X' : 'O');
			if (i % fl->y == fl->y - 1)
				ft_putchar('\n');
			i++;
		}
	}
}

void		test_print_piece(t_fl *fl)
{
	int		i;
	int		pxy;

	if (fl->p)
	{
		ft_putchar('\n');
		ft_printf("Piece %d %d\n", fl->px, fl->py);
		i = 0;
		pxy = fl->px * fl->py;
		while (i < pxy)
		{
			if (fl->p[i] == 0)
				ft_putchar('.');
			else if (fl->p[i] == 1)
				ft_putchar('*');
			if (i % fl->py == fl->py - 1)
				ft_putchar('\n');
			i++;
		}
	}
}

int			fl(void)
{
	t_fl	*fl;

	fl = init_fl();
	ft_fl_delete(&fl);
	return (0);
}

int			main(void)
{
	fl();
	return (0);
}
