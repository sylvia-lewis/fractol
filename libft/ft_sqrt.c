/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:20:59 by sylewis           #+#    #+#             */
/*   Updated: 2019/02/09 14:38:59 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int sqrt;

	sqrt = 1;
	if (nb >= 0)
	{
		while ((sqrt * sqrt) != nb)
		{
			if (sqrt != 46340)
				sqrt++;
			else
				return (0);
		}
		return (sqrt);
	}
	else
		return (0);
}
