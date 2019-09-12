/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:32:15 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/07 18:50:26 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(*s) * (size))))
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
