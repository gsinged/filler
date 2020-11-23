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

void		ft_piece_delete(t_fl *fl)
{
	if (fl->piece)
	{
		ft_bzero(fl->piece, (fl->px * fl->py * sizeof(int)));
		free(fl->piece);
		fl->piece = NULL;
		fl->px = 0;
		fl->py = 0;
		fl->pxy = 0;
	}
}

void		ft_fl_delete(t_fl **fl)
{
	if (fl && *fl)
	{
		if ((*fl)->map)
		{
			ft_bzero((*fl)->map, ((*fl)->x * (*fl)->y * sizeof(int)));
			free((*fl)->map);
		}
		if ((*fl)->piece)
		{
			ft_bzero((*fl)->piece, ((*fl)->px * (*fl)->py * sizeof(int)));
			free((*fl)->piece);
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

void		test_print_piece(t_fl *fl)
{
	int		i;
	int		pxy;

	if (fl->piece)
	{
//		ft_putchar('\n');
		ft_printf("Piece %d %d\n", fl->px, fl->py);
		i = 0;
		pxy = fl->px * fl->py;
		while (i < pxy)
		{
			if (fl->piece[i] == 0)
				ft_putchar('.');
			else if (fl->piece[i] == 1)
				ft_putchar('*');
			if (i % fl->py == fl->py - 1)
				ft_putchar('\n');
			i++;
		}
	}
}

void		test_print_map(t_fl *fl)
{
	int		i;
	int		xy;
	int		t;

	if (fl->map)
	{
		xy = fl->x * fl->y;
		ft_putchar('\n');
		ft_printf("Plateau %d %d\n", fl->x, fl->y);
		ft_putstr("    ");
		i = 0;
		while (i < fl->y)
		{
			t = i % 10;
			ft_printf("%2c", '0' + t);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		i = 0;
		while (i < xy)
		{
			if (!(i % fl->y))
				ft_printf("%03d ", i / fl->y);
			if (fl->map[i] == 0)
				ft_printf("%2c", '.');
			else if (fl->map[i] > 0 )
				ft_printf("%2d", fl->map[i]);
			else if (fl->map[i] == -1)
				ft_printf("\e[%dm%2c\e[39m", 92, (fl->pl == 1 ? 'O' : 'X'));
			else if (fl->map[i] == -2)
				ft_printf("\e[%dm%2c\e[39m", 91, fl->pl == 1 ? 'X' : 'O');
			if (i % fl->y < fl->y - 1)
				ft_putchar(' ');
			else
				ft_putchar('\n');
			i++;
		}
	}
	test_print_piece(fl);
}


int			fl(void)
{
	t_fl *fl;

	fl = init_fl();
	manhattan(fl);
//	test_print_piece(fl);
//	ft_printf("Manhatten\n");
//	test_print_map(fl);
	select_coordinates(fl);

	while (get_map(fl))
	{
		manhattan(fl);
		select_coordinates(fl);
	}
	ft_fl_delete(&fl);
	return (0);
}

int			main(void)
{
	fl();
	return (0);
}
