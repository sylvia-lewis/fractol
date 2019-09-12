/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:14:30 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/07 11:47:53 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*lst_ptr;

	lst_ptr = lst;
	while (lst_ptr)
	{
		f(lst_ptr);
		lst_ptr = lst_ptr->next;
	}
}
