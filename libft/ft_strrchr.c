/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:34:13 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/06 15:46:45 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)s;
	while (str[i] != '\0')
		i++;
	while (str[i] != c && i >= 0)
		i--;
	if (str[i] == c)
		return (str + i);
	else
		return (NULL);
}
