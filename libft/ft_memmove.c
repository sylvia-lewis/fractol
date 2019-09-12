/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:03:55 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/07 20:26:58 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest;
	char	*source;

	i = 0;
	dest = (char*)dst;
	source = (char*)src;
	if (source < dest)
	{
		while (len != 0)
		{
			*(dest + len - 1) = *(source + len - 1);
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			*(dest + i) = *(source + i);
			i++;
		}
	}
	return (dst);
}
