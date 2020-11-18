/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelcontent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 00:17:42 by gsinged           #+#    #+#             */
/*   Updated: 2019/11/27 00:17:44 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelcontent(t_list **alst)
{
	if (alst && *alst)
	{
		ft_strclr((*alst)->content);
		ft_strdel((char **)&((*alst)->content));
		(*alst)->content_size = 0;
	}
}
