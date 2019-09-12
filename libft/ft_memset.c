/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:51:19 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/05 10:35:12 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;

	a = b;
	while (len != 0)
	{
		*a++ = (unsigned char)c;
		len--;
	}
	return (b);
}
