/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:54:57 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:55:00 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_fnum	*ft_fnum_new(void)
{
	t_fnum	*fn;

	if (!(fn = (t_fnum *)malloc(sizeof(t_fnum))))
		return (NULL);
	return (fn);
}
