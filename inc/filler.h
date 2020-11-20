/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:30:43 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/18 19:30:44 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdlib.h>

typedef struct	s_filler
{
	int			pl;
	int			x;
	int			y;
	int			xy;
	int			*map;
	int			size;
	int			px;
	int			py;
	int			*p;
}				t_fl;

t_fl			*init_fl(void);
int				init_map(t_fl *fl);

int				get_size_map_a(char *line, int *xy);
int				get_size_map(t_fl *fl);
int				nbr_dig_nbr(int n);

int				ft_error(void);
t_fl			*ft_error_tfl(void);

#endif
