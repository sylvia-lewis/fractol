/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:10:43 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/08 11:39:22 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp1;

	tmp1 = *alst;
	del(tmp1->content, tmp1->content_size);
	free(tmp1);
	*alst = NULL;
}
