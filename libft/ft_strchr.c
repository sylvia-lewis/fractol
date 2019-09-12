/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:32:18 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/06 15:45:31 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)s;
	while (str[i] != '\0' && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return (str + i);
	else
		return (NULL);
}
