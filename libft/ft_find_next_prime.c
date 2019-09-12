/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:25:30 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/08 17:10:48 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_next_prime(int nb)
{
	int np;
	int i;

	i = 0;
	if (nb == 0)
		np = 1;
	if (nb == 1)
		np = 2;
	while (ft_is_prime(nb + i) == 0)
		i++;
	np = nb + i;
	return (np);
}
