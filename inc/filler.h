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

# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))
# define FT_MAX(A, B) (((A) > (B)) ? (A) : (B))
# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))

typedef struct	s_filler
{
	int			pl;
	int			x;
	int			y;
	int			xy;
	int			*map;
	int			px;
	int			py;
	int			pxy;
	int			*piece;
	int			mpx;
	int 		mpy;
	int			mpxy;
}				t_fl;

t_fl			*init_fl(void);
int				init_map(t_fl *fl);

int				get_size_map_a(char *line, int *xy);
int				get_size_map(t_fl *fl);
int				init_map_f_str(t_fl *fl);
int				nbr_dig_nbr(int n);
int				init_map_line_p1(t_fl *fl, char *line, int x);
int				init_map_line_p2(t_fl *fl, char *line, int x);
int				get_piece(t_fl *fl);

int				manhattan(t_fl *fl);
int				select_coordinates(t_fl *fl);

int				get_map(t_fl *fl);

int				ft_error(void);
t_fl			*ft_error_tfl(void);


void			test_print_map(t_fl *fl);

#endif
