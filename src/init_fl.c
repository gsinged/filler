/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:17:22 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/19 23:17:23 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			get_player(t_fl *fl)
{
	char	*line;
	char	*s;

	line = NULL;
	if ((get_next_line(0, &line) != 1))
		return (ft_error(fl, &line));
	if (ft_strncmp(line, "$$$ exec p", 10))
		return (ft_error(fl, &line));
	if (*(line + 10) == '1')
		fl->pl = 1;
	else if (*(line + 10) == '2')
		fl->pl = 2;
	else
		return (ft_error(fl, &line));
	if (ft_strncmp(line + 11, " : [", 4))
		return (ft_error(fl, &line));
	if (!(s = ft_strstr(line, "gsinged.filler]")))
		return (ft_error(fl, &line));
	if (ft_strcmp(s, "gsinged.filler]"))
		return (ft_error(fl, &line));
	ft_strclr(line);
	free(line);
	return (1);
}

int			get_size_piece(t_fl *fl)
{
	char	*line;
	int		i;

	line = NULL;
	if ((get_next_line(0, &line) != 1))
		return (ft_error(fl, &line));
	if (ft_strncmp(line, "Piece ", 6))
		return (ft_error(fl, &line));
	if (!(i = get_size_map_a(line + 6, &(fl->px))))
		return (ft_error(fl, &line));
	if (*(line + 6 + i) != ' ')
		return (ft_error(fl, &line));
	if (!(i += get_size_map_a(line + 7 + i, &(fl->py))))
		return (ft_error(fl, &line));
	if (ft_strcmp(line + 7 + i, ":"))
		return (ft_error(fl, &line));
	fl->pxy = fl->px * fl->py;
	ft_strclr(line);
	free(line);
	return (1);
}

int			init_piece_line(t_fl *fl, char *line, int x)
{
	int		i;

	i = 0;
	while (i < fl->py)
	{
		if (*(line + i) == '*')
			fl->piece[fl->py * x + i] = 1;
		else if (*(line + i) != '.')
			return (ft_error(fl, &line));
		i++;
	}
	if (*(line + fl->py) != '\0')
		return (ft_error(fl, &line));
	return (1);
}

int			get_piece(t_fl *fl)
{
	int		*p;
	int		i;
	char	*line;

	line = NULL;
	if (!(get_size_piece(fl)))
		return (0);
	if (!(p = (int*)malloc(sizeof(int) * fl->pxy)))
		return (ft_error(fl, NULL));
	ft_bzero(p, sizeof(int) * fl->pxy);
	fl->piece = p;
	i = 0;
	while (i < fl->px)
	{
		if ((get_next_line(0, &line) != 1))
			return (ft_error(fl, &line));
		if (!(init_piece_line(fl, line, i++)))
			return (0);
		ft_strclr(line);
		free(line);
	}
	fl->mpx = fl->x + fl->px * 2;
	fl->mpy = fl->y + fl->py * 2;
	fl->mpxy = fl->mpx * fl->mpy;
	return (1);
}

t_fl		*init_fl(void)
{
	t_fl		*fl;

	if (!(fl = (t_fl*)malloc(sizeof(t_fl))))
		return (ft_error_tfl(fl, NULL));
	ft_bzero(fl, sizeof(t_fl));
	if (!(get_player(fl)))
		return (NULL);
	if (fl->pl == 1)
		fl->init_map_line = init_map_line_p1;
	else
		fl->init_map_line = init_map_line_p2;
	if (!(init_map(fl)))
		return (0);
	if (!(get_piece(fl)))
		return (0);
	return (fl);
}
