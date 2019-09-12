/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:35:39 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/07 14:06:14 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strstr(const char *haystack, const char *needle)
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
	while (haystack[i] != '\0')
	{
		while (haystack[i + j] == needle[j])
		{
			if (j == size - 1)
				return ((char*)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
