/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:22:05 by gsinged           #+#    #+#             */
/*   Updated: 2019/10/24 13:22:09 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_list	*ft_begin(t_list *lst, t_list *(*f)(t_list *elem), t_list **mid)
{
	t_list	*begin;

	if (!(begin = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	begin = f(begin);
	*mid = begin;
	return (begin);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*new;
	t_list	*mid;

	if (lst && f)
	{
		if (!(begin = ft_begin(lst, f, &mid)))
			return (NULL);
		lst = lst->next;
	}
	else
		return (NULL);
	while (lst)
	{
		if (!(new = ft_lstnew(lst->content, lst->content_size)))
		{
			ft_lstdel(&begin, ft_bzero);
			return (NULL);
		}
		new = f(new);
		lst = lst->next;
		mid->next = new;
		mid = mid->next;
	}
	return (begin);
}
