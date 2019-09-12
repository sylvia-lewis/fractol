/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:07:45 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/16 20:45:38 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

t_list		**ft_split_lst(char const *s, char c)
{
	t_list	**begin_list;
	int		i;
	int		k;
	char	*cont;

	i = 0;
	k = 0;
	str = (char*)s;
	if (s == '\0')
		return (NULL);
	while (str[i] != '\0')
	{
		if (!(str[i] == c))
		{
			i = ft_modstrcpy(i, cont, str, c);
			tmp = ft_lstnew((const)cont, sizeof(char) * cnt(i, str, c));
		}
		while (str[i] == c)

