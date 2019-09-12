/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:16:23 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/08 12:57:55 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count(int n)
{
	int		i;
	int		nb;

	i = 0;
	nb = n;
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

static char	*ft_malstr(int i)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	return (str);
}

static char	*ft_min(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static char	*zero(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	i = ft_count(n) - 1;
	sign = 1;
	if (!(str = ft_malstr(i)))
		return (NULL);
	if (n == -2147483648)
		return (ft_min(str));
	if (n == 0)
		return (zero(str));
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	while (n > 0)
	{
		str[i--] = n % 10 + 48;
		n = n / 10;
	}
	if (sign == -1)
		str[i--] = '-';
	return (str);
}
