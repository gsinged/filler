/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:50:09 by gsinged           #+#    #+#             */
/*   Updated: 2019/10/23 21:50:11 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (alst && *alst)
	{
		while (*alst)
		{
			next = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = next;
		}
	}
}
