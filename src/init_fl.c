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
			fl->piece[fl->py * x + i] = 1;
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
	fl->piece = p;
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
	init_map(fl);
	get_piece(fl);
	if ((get_next_line(0, &line) != 0))
		return (ft_error_tfl());
	return (fl);
}
