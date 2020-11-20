/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:12:16 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/20 17:12:17 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

int			get_size_map_a(char *line, int *xy)
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
