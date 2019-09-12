/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:40:24 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/07 14:16:33 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (needle[size] != '\0')
		size++;
	while (haystack[i] != '\0' && i + j < (int)len)
	{
		while (haystack[i + j] == needle[j] && i + j < (int)len)
		{
			if (j == size - 1)
				return ((char*)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
