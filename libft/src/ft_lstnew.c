/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:14:34 by gsinged           #+#    #+#             */
/*   Updated: 2019/10/18 17:14:37 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_null(t_list **new)
{
	(*new)->content = NULL;
	(*new)->content_size = 0;
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		ft_null(&new);
	else
	{
		if (!(new->content = (void*)malloc(content_size)))
		{
			free(new);
			return (NULL);
		}
		if (!(new->content = \
							ft_memcpy(new->content, content, content_size)))
		{
			free(new);
			free(new->content);
			return (NULL);
		}
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
