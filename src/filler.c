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
#include <stdlib.h>

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

int			get_player(t_fl *fl)
{
	char	*line;
	char	*s;

	if ((get_next_line(0, &line) != 1))
		return (ft_error());
	if (ft_strncmp(line, "$$$ exec p", 10))
		return (ft_error());
	if (*(line + 10) == '1')
		fl->pl = 1;
	else if (*(line + 10) == '2')
		fl->pl = 2;
	else
		return (ft_error());
	if (ft_strncmp(line + 11, " : [", 4))
		return (ft_error());
	if (!(s = ft_strstr(line, "gsinged.filler]")))
		return (ft_error());
	if (ft_strcmp(s, "gsinged.filler]"))
		return (ft_error());
	ft_strclr(line);
	free(line);
	return (0);
}

int			nbr_dig_nbr(int n)
{
	int		i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	get_size_map_a(char *line, int *xy)
{
	int		i;

	i = 0;
	if (ft_isdigit(*line))
	{
		*xy = ft_atoi(line);
		i = nbr_dig_nbr(*xy);
	}
	return (i);
}

int			get_size_map(t_fl *fl)
{
	char	*line;
	int		i;

	if ((get_next_line(0, &line) != 1))
		return (ft_error());
	if (ft_strncmp(line, "Plateau ", 8))
		return (ft_error());
	if (!(i = get_size_map_a(line + 8, &(fl->x))))
		return (ft_error());
	if (*(line + 8 + i) != ' ')
		return (ft_error());
	if (!(i += get_size_map_a(line + 9 + i, &(fl->y))))
		return (ft_error());
	if (ft_strcmp(line + 9 + i, ":"))
		return (ft_error());
	fl->xy = fl->x * fl->y;
	ft_strclr(line);
	free(line);
	return (0);
}

int			init_map_f_str(t_fl *fl)
{
	const char	ten[10];
	char		*line;
	int			i;

	if ((get_next_line(0, &line) != 1))
		return (ft_error());
	if (ft_strncmp(line, "    ", 4))
		return (ft_error());
	i = 0;
	ft_memcpy((void*)ten, "0123456789", 10);
	while (i < fl->y)
	{
		if (*(line + 4 + i) != ten[i % 10])
			return (ft_error());
		i++;
	}
	if (*(line + 4 + fl->y) != '\0')
		return (ft_error());
	ft_strclr(line);
	free(line);
	return (0);
}

static char	*first_symb_line(char *line, int i, int n)
{
	if (i < 10)
	{
		if (ft_strncmp(line, "00", 2))
			return ((char*)ft_error_tfl());
		if (*(line + 2) != '0' + i)
			return ((char*)ft_error_tfl());
	}
	else if (i < 100)
	{
		if (ft_strncmp(line, "0", 1))
			return ((char*)ft_error_tfl());
		if ((*(line + 1) != '0' + i / 10) && (*(line + 2) != '0' + i % 10))
			return ((char*)ft_error_tfl());
	}
	else if (i >= 1000)
	{
		n = ft_atoi(line);
		if ((*line < '1' || *line > '9') && n != i)
			return ((char *)ft_error_tfl());
		n = nbr_dig_nbr(n);
	}
	if (*(line + n) != ' ')
		return ((char*)ft_error_tfl());
	return (line + n + 1);
}

int			init_map_line_p1(t_fl *fl, char *line, int x)
{
	char	*s;
	int		i;

	s = first_symb_line(line, x, 3);
	i = 0;
	while (i < fl->y)
	{
		if (*(s + i) == 'o' || *(s + i) == 'O')
			fl->map[fl->y * x + i] = 1;
		else if (*(s + i) == 'x' || *(s + i) == 'X')
			fl->map[fl->y * x + i] = -1;
		else if (*(s + i) != '.')
			return (ft_error());
		i++;
	}
	if (*(s + fl->y) != '\0')
		return (ft_error());
	return (0);
}

int			init_map_line_p2(t_fl *fl, char *line, int x)
{
	char	*s;
	int		i;

	s = first_symb_line(line, x, 3);
	i = 0;
	while (i < fl->y)
	{
		if (*(s + i) == 'x' || *(s + i) == 'X')
			fl->map[fl->y * x + i] = 1;
		else if (*(s + i) == 'o' || *(s + i) == 'O')
			fl->map[fl->y * x + i] = -1;
		else if (*(s + i) != '.')
			return (ft_error());
		i++;
	}
	if (*(s + fl->y) != '\0')
		return (ft_error());
	return (0);
}

int			init_map(t_fl *fl)
{
	int		*map;
	int		i;
	char	*line;

	if (!(map = (int*)malloc(sizeof(int) * fl->xy)))
		return (ft_error());
	ft_bzero(map, sizeof(int) * fl->xy);
	fl->map = map;
	i = 0;
	while (i < fl->x)
	{
		if ((get_next_line(0, &line) != 1))
			return (ft_error());
		if (fl->pl == 1)
			init_map_line_p1(fl, line, i);
		else if (fl->pl == 2)
			init_map_line_p2(fl, line, i);
		ft_strclr(line);
		free(line);
		i++;
	}
	return (0);
}

int			get_map(t_fl *fl)
{
	get_size_map(fl);
	init_map_f_str(fl);
	init_map(fl);
	return (0);
}

int			get_size_piece(t_fl *fl)
{
	char	*line;
	int		i;

	if ((get_next_line(0, &line) != 1))
		return (ft_error());
	if (ft_strncmp(line, "Piece ", 6))
		return (ft_error());
	if (!(i = get_size_map_a(line + 6, &(fl->px))))
		return (ft_error());
	if (*(line + 6 + i) != ' ')
		return (ft_error());
	if (!(i += get_size_map_a(line + 7 + i, &(fl->py))))
		return (ft_error());
	if (ft_strcmp(line + 7 + i, ":"))
		return (ft_error());
	ft_strclr(line);
	free(line);
	return (0);
}

int			init_piece_line(t_fl *fl, char *s, int x)
{
	int		i;

	i = 0;
	while (i < fl->py)
	{
		if (*(s + i) == '*')
			fl->p[fl->py * x + i] = 1;
		else if (*(s + i) != '.')
			return (ft_error());
		i++;
	}
	if (*(s + fl->py) != '\0')
		return (ft_error());
	return (0);
}

int			get_piece(t_fl *fl)
{
	int		*p;
	int		i;
	char	*line;

	get_size_piece(fl);
	if (!(p = (int*)malloc(sizeof(int) * fl->px * fl->py)))
		return (ft_error());
	ft_bzero(p, sizeof(int) * fl->px * fl->py);
	fl->p = p;
	i = 0;
	while (i < fl->px)
	{
		if ((get_next_line(0, &line) != 1))
			return (ft_error());
		init_piece_line(fl, line, i);
		ft_strclr(line);
		free(line);
		i++;
	}
	return (0);
}

t_fl		*init_fl(void)
{
	t_fl		*fl;
	char		*line;

	if (!(fl = (t_fl*)malloc(sizeof(t_fl))))
		return (ft_error_tfl());
	ft_bzero(fl, sizeof(t_fl));
	get_player(fl);
	get_map(fl);
	get_piece(fl);
	if ((get_next_line(0, &line) != 0))
		return (ft_error_tfl());
	return (fl);
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
