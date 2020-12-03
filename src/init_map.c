/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:20:40 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/19 23:20:41 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			init_map_f_str(t_fl *fl)
{
	const char	ten[10];
	char		*line;
	int			i;

	if ((get_next_line(0, &line) != 1))
		return (ft_error(fl, &line));
	if (ft_strncmp(line, "    ", 4))
		return (ft_error(fl, &line));
	i = 0;
	ft_memcpy((void*)ten, "0123456789", 10);
	while (i < fl->y)
	{
		if (*(line + 4 + i) != ten[i % 10])
			return (ft_error(fl, &line));
		i++;
	}
	if (*(line + 4 + fl->y) != '\0')
		return (ft_error(fl, &line));
	ft_strclr(line);
	free(line);
	return (1);
}

static char	*first_symb_line(char *line, int i, int n)
{
	if (i < 10)
	{
		if (ft_strncmp(line, "00", 2))
			return (NULL);
		if (*(line + 2) != '0' + i)
			return (NULL);
	}
	else if (i < 100)
	{
		if (ft_strncmp(line, "0", 1))
			return (NULL);
		if ((*(line + 1) != '0' + i / 10) && (*(line + 2) != '0' + i % 10))
			return (NULL);
	}
	else if (i >= 1000)
	{
		n = ft_atoi(line);
		if ((*line < '1' || *line > '9') && n != i)
			return (NULL);
		n = nbr_dig_nbr(n);
	}
	if (*(line + n) != ' ')
		return (NULL);
	return (line + n + 1);
}

int			init_map_line_p1(t_fl *fl, char *line, int x)
{
	char	*s;
	int		i;

	if (!(s = first_symb_line(line, x, 3)))
		return (ft_error(fl, &line));
	i = 0;
	while (i < fl->y)
	{
		if (*(s + i) == 'o' || *(s + i) == 'O')
			fl->map[fl->y * x + i] = -1;
		else if (*(s + i) == 'x' || *(s + i) == 'X')
			fl->map[fl->y * x + i] = -2;
		else if (*(s + i) != '.')
			return (ft_error(fl, &line));
		i++;
	}
	if (*(s + fl->y) != '\0')
		return (ft_error(fl, &line));
	return (1);
}

int			init_map_line_p2(t_fl *fl, char *line, int x)
{
	char	*s;
	int		i;

	if (!(s = first_symb_line(line, x, 3)))
		return (ft_error(fl, &line));
	i = 0;
	while (i < fl->y)
	{
		if (*(s + i) == 'x' || *(s + i) == 'X')
			fl->map[fl->y * x + i] = -1;
		else if (*(s + i) == 'o' || *(s + i) == 'O')
			fl->map[fl->y * x + i] = -2;
		else if (*(s + i) != '.')
			return (ft_error(fl, &line));
		i++;
	}
	if (*(s + fl->y) != '\0')
		return (ft_error(fl, &line));
	return (1);
}

int			init_map(t_fl *fl)
{
	int		*map;
	int		i;
	char	*line;

	get_size_map(fl);
	init_map_f_str(fl);
	if (!(map = (int*)malloc(sizeof(int) * fl->xy)))
		return (ft_error(fl, NULL));
	ft_bzero(map, sizeof(int) * fl->xy);
	fl->map = map;
	i = 0;
	while (i < fl->x)
	{
		if ((get_next_line(0, &line) != 1))
			return (ft_error(fl, &line));
		if (!(fl->init_map_line(fl, line, i)))
			return (ft_error(fl, &line));
		ft_strclr(line);
		free(line);
		i++;
	}
	return (1);
}
