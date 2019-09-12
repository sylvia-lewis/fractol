/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 11:26:40 by sylewis           #+#    #+#             */
/*   Updated: 2019/04/11 18:47:21 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_lstfind(t_list *begin_list, int nb)
{
	t_list *tmp;

	tmp = begin_list;
	while (tmp)
	{
		if (tmp->nb == nb)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}
