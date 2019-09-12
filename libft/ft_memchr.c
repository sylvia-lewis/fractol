/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:05:32 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/05 10:55:10 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	str = (char*)s;
	while (n != 0 && *str != (char)c)
	{
		str++;
		n--;
	}
	if (n != 0)
		return (str);
	else
		return (NULL);
}
