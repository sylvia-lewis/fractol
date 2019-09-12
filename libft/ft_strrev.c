/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:51:50 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/08 17:03:31 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		strlen;
	int		i;
	char	intmdt;

	i = 0;
	strlen = ft_strlen(str);
	while (i < strlen / 2)
	{
		intmdt = str[(strlen - 1 - i)];
		str[(strlen - 1 - i)] = str[i];
		str[i] = intmdt;
		i++;
	}
	return (str);
}
