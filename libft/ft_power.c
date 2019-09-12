/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:08:27 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/08 17:08:46 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int nb, int power)
{
	if (power > 1)
	{
		return (nb * ft_power(nb, power - 1));
	}
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	else
		return (0);
}
