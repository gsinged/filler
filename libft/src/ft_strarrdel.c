/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:53:52 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/28 19:53:57 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strarrdel(int ln, char ***arr)
{
	int		n;
	char	**arr1;

	n = 0;
	arr1 = *arr;
	while (n < ln)
	{
		ft_strdel(&arr1[n]);
		n++;
	}
	free(arr);
}
