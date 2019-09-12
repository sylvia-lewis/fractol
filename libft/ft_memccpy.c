/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:02:00 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/07 18:33:23 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		if (((unsigned char*)src)[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
