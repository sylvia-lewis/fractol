/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:54:12 by sylewis           #+#    #+#             */
/*   Updated: 2019/02/09 20:07:26 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int intmdt;
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < j && j < size)
	{
		if (tab[i] > tab[j])
		{
			intmdt = tab[i];
			tab[i] = tab[j];
			tab[j] = intmdt;
		}
		j++;
		if (j == size)
		{
			i++;
			j = i + 1;
		}
	}
}
