/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:06:54 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/07 14:11:19 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				diff;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	diff = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && str1[i] == str2[i])
		i++;
	if (str1[i] != str2[i])
	{
		diff = str1[i] - str2[i];
		return (diff);
	}
	else
		return (0);
}
