/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:35:01 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/08 16:18:29 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	del(void *content, size_t content_size)
{
	content = NULL;
	free(content);
	content_size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_list;
	t_list	*list_ptr;
	t_list	*curr;
	t_list	*next;

	list_ptr = lst;
	begin_list = f(list_ptr);
	curr = begin_list;
	next = NULL;
	while (list_ptr->next)
	{
		curr->next = f(list_ptr->next);
		if (curr->next == NULL)
		{
			ft_lstdel(&begin_list, del);
			return (NULL);
		}
		curr = curr->next;
		list_ptr = list_ptr->next;
	}
	return (begin_list);
}
