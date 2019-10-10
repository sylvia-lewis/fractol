/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:16:58 by sylewis           #+#    #+#             */
/*   Updated: 2019/10/10 17:55:03 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	zoom(t_info *info)
{
	info->x_range *= 0.1;
	info->y_range *= 0.1;
	while (y < PIXELS_Y)
	{
		x = 0;
		while (x < PIXELS_X)
		{
			info->point.a = info->mouse.x + (info->x_range / PIXELS_X) * (info->point.a - info->mouse.x);
			info->point.b = info->mouse.y + (info->y_range / PIXELS_Y) * (info->point.b - info->mouse.y);
			x++;
		}
		y++;
	}
	
}