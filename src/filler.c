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

void			ft_fl_delete(t_fl **fl)
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

t_fl			*ft_error_tfl(void)
{
	exit(0);
}

int				ft_error(void)
{
	exit(0);
}

int				get_player(t_fl *fl)
{
	char 	*line;
	char	*s;

	if ((get_next_line(0, &line) != 1))
		return (ft_error());
	if (ft_strncmp(line, "$$$ exec p", 10))
		return (ft_error());
	if (*(line + 10) == '1')
		ft_strcpy(fl->p, "oO");
	else if (*(line + 10) == '2')
		ft_strcpy(fl->p, "xX");
	else
		return (ft_error());
	if (ft_strncmp(line + 11, " : [", 4))
		return (ft_error());
	if (!(s = ft_strstr(line, "gsinged.filler]")))
		return (ft_error());
	if (ft_strcmp(s, "gsinged.filler]"))
		return (ft_error());
	ft_strclr(line);
	free (line);
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

static int	get_size_map_a(char *line, int	*xy)
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
	char 	*line;
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
	free (line);
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
	free (line);
	return (0);

}

static char	*first_symb_line(t_fl *fl, char *line, int i, int n)
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
			if ((*line < '1' || *line > '9') && (n = ft_atoi(line)) != i)
				return ((char*)ft_error_tfl());
			n = nbr_dig_nbr(n);
	}
	if (*(line + n) != ' ')
		return ((char*)ft_error_tfl());
	return (line + n + 1);
}

int			init_map_line(t_fl *fl, char *line, int x, int n)
{
	char	*s;
	int		i;

	s = first_symb_line(fl, line, x, 3);
	i = 0;
	while (i < fl->y)
	{
		
	}


}

int			init_map(t_fl *fl)
{
	int		*map;
	int		i;

	if (!(map = (int*)malloc(sizeof(int) * fl->xy)))
		return (ft_error());
	i = 0;
	while (i < fl->x)
	{


	}



	return (0);
}

int			get_map(t_fl *fl)
{
	get_size_map(fl);
	init_map_f_str(fl);
	init_map(fl);



	return(0);

}

t_fl		*init_fl(void)
{
	t_fl		*fl;

	if (!(fl = (t_fl*)malloc(sizeof(t_fl))))
		return (ft_error_tfl());
	ft_bzero(fl, sizeof(t_fl));
	get_player(fl);
	get_map(fl);

	char *line;
	while (get_next_line(0, &line))
	{
		ft_printf("||||%s\n", line);
		ft_strclr(line);
		free (line);
	}


	return(fl);
}


int			fl(void)
{
	t_fl	*fl;

	fl = init_fl();
	ft_printf("OK, %c%c\n", fl->p[0], fl->p[1]);

	ft_fl_delete(&fl);
	return (0);
}

int			main(void)
{
	fl();

	return (0);
}