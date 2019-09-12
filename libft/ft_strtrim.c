/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:32:27 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/08 12:20:43 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_find_i(char const *s)
{
	int		i;

	i = 0;
	if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
	}
	return (i);
}

static int	ft_find_j(char const *s)
{
	int		j;

	j = 0;
	while (s[j] != '\0')
		j++;
	if (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
	{
		while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
			j--;
	}
	return (j);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (s == '\0')
		return (NULL);
	i = ft_find_i(s);
	j = ft_find_j(s);
	if (i < j)
	{
		k = 0;
		if (!(str = (char*)malloc(sizeof(*str) * (j - i + 1))))
			return (NULL);
		while (i < j)
			str[k++] = s[i++];
		str[k] = '\0';
		return (str);
	}
	if (!(str = (char*)malloc(sizeof(*str))))
		return (NULL);
	str[0] = '\0';
	return (str);
}
