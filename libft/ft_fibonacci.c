/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:10:54 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/08 17:09:49 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int fib;

	if (index >= 2)
	{
		fib = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
		return (fib);
	}
	else if (index == 1)
		return (1);
	else if (index == 0)
		return (0);
	else
		return (-1);
}
