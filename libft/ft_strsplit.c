/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:13:05 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/08 12:17:45 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_splits(char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == c))
		{
			while (!(s[i] == c || s[i] == '\0'))
				i++;
			count++;
		}
		while (s[i] == c)
			i++;
	}
	return (count);
}

static int	cnt(int i, char *s, char c)
{
	int		count;

	count = 0;
	while (!(s[i] == c || s[i] == '\0'))
	{
		i++;
		count++;
	}
	return (count);
}

static int	ft_modstrcpy(int i, char *dest, char *s, char c)
{
	int		j;

	j = 0;
	while (!(s[i] == c || s[i] == '\0'))
	{
		dest[j] = s[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	char	**sr;
	char	*str;

	i = 0;
	k = 0;
	str = (char*)s;
	if (s == '\0')
		return (NULL);
	if (!(sr = (char**)malloc(sizeof(char*) * (ft_splits(str, c) + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		if (!(str[i] == c))
		{
			if (!(sr[k] = (char*)malloc(sizeof(char) * (cnt(i, str, c) + 1))))
				return (NULL);
			i = ft_modstrcpy(i, sr[k++], str, c);
		}
		while (str[i] == c)
			i++;
	}
	sr[k] = NULL;
	return (sr);
}
