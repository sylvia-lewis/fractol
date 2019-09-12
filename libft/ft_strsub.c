/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:39:32 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/07 16:02:50 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	if (s)
	{
		while (i < (unsigned int)len && s[start + i] != '\0')
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
