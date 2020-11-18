/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frmt_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:55:41 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:55:43 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_frmt_spec		*ft_new_frmt_spec(void)
{
	t_frmt_spec		*frmt;

	if (!(frmt = (t_frmt_spec *)malloc(sizeof(*frmt))))
		return (NULL);
	return (frmt);
}

void			ft_frmt_spec_0(t_frmt_spec *f)
{
	f->type = 0;
	f->width = 0;
	f->precision = 0;
	f->length = 0;
	f->plus = 0;
	f->space = 0;
	f->sharp = 0;
	f->left = 0;
	f->zero = 0;
	f->spec = 0;
	f->prec = 0;
	f->sign = 0;
	f->error = 0;
}
