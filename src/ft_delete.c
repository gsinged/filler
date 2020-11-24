/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:12:41 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/25 00:12:43 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_piece_delete(t_fl *fl)
{
	if (fl->piece)
	{
		ft_bzero(fl->piece, (fl->pxy * sizeof(int)));
		free(fl->piece);
		fl->piece = NULL;
		fl->px = 0;
		fl->py = 0;
		fl->pxy = 0;
	}
}

void		ft_fl_delete(t_fl **fl)
{
	if (fl && *fl)
	{
		if ((*fl)->map)
		{
			ft_bzero((*fl)->map, ((*fl)->xy * sizeof(int)));
			free((*fl)->map);
		}
		if ((*fl)->piece)
		{
			ft_bzero((*fl)->piece, ((*fl)->pxy * sizeof(int)));
			free((*fl)->piece);
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
