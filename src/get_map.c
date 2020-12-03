/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:03:10 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/22 20:03:12 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_size_map_a(char *line, int *xy0)
{
	int		i;
	int		xy;

	i = 0;
	if (ft_isdigit(*line))
	{
		xy = ft_atoi(line);
		if (xy != *xy0)
			return (0);
		i = nbr_dig_nbr(xy);
	}
	return (i);
}

int			check_size_map(t_fl *fl)
{
	char	*line;
	int		i;

	if ((get_next_line(0, &line) != 1))
		return (ft_error(fl, &line));
	if (ft_strncmp(line, "Plateau ", 8))
		return (ft_error(fl, &line));
	if (!(i = check_size_map_a(line + 8, &(fl->x))))
		return (ft_error(fl, &line));
	if (*(line + 8 + i) != ' ')
		return (ft_error(fl, &line));
	if (!(i += check_size_map_a(line + 9 + i, &(fl->y))))
		return (ft_error(fl, &line));
	if (ft_strcmp(line + 9 + i, ":"))
		return (ft_error(fl, &line));
	fl->xy = fl->x * fl->y;
	ft_strclr(line);
	free(line);
	return (1);
}

int			get_map(t_fl *fl)
{
	int		i;
	char	*line;

	if (!(check_size_map(fl)))
		return (0);
	if (!(init_map_f_str(fl)))
		return (0);
	ft_bzero(fl->map, sizeof(int) * fl->xy);
	i = 0;
	while (i < fl->x)
	{
		if ((get_next_line(0, &line) != 1))
			return (ft_error(fl, &line));
		if (!(fl->init_map_line(fl, line, i)))
			return (0);
		ft_strclr(line);
		free(line);
		i++;
	}
	ft_piece_delete(fl);
	if (!(get_piece(fl)))
		return (0);
	return (1);
}
