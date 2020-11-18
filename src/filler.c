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
	exit (0);
}

int				ft_error(void)
{
	exit(0);
}

int				check_name(char *line)
{
	char	*s;
	if (!(s = ft_strstr(line, "gsinged.filler]")))
		return (ft_error());
	if (ft_strcmp(s, "gsinged.filler]"))
		return (ft_error());
	return (1);
}

int				get_player(t_fl *fl)
{
	char 	*line;

	get_next_line(0, &line);
	ft_printf("%s\n", line);
//	if ((get_next_line(0, &line) == 1))
//		return (ft_error());
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
	check_name(line + 15);
	ft_strclr(line);
	free (line);
	return (0);
}

t_fl		*init_fl(void)
{
	t_fl		*fl;

	if (!(fl = (t_fl*)malloc(sizeof(t_fl))))
		return (ft_error_tfl());
	ft_bzero(fl, sizeof(t_fl));
	get_player(fl);
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