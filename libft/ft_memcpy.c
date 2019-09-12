/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:00:43 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/05 11:47:17 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*pd;
	const char	*ps;

	pd = dst;
	ps = src;
	while (n != 0)
	{
		*pd++ = *ps++;
		n--;
	}
	return (dst);
}
