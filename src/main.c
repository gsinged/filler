/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:21:01 by gsinged           #+#    #+#             */
/*   Updated: 2020/12/03 13:21:03 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			fl(void)
{
	t_fl *fl;

	if (!(fl = init_fl()))
		return (0);
	manhattan(fl);
	select_coordinates(fl);
	while (get_map(fl))
	{
		manhattan(fl);
		select_coordinates(fl);
	}
	return (0);
}

int			main(void)
{
	fl();
	return (0);
}
