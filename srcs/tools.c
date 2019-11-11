/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:16:58 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/11 17:34:17 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	zoom(t_info *info, t_frac *frac)
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

/*
	coords at (0,0) + range
	eg start at -2,2 range 3.7 * 4.2 => end 1.7,-2.2
	go to next pixel => (0,0) + (range/no. pix)
*/


void	zoom(t_info *info, t_frac *frac)
{
	info->x_range *= 0.1;
	info->y_range *= 0.1;

	frac->origin.a = info->mouse.x + (info->x_range / PIXELS_X) * (frac->origin.a - info->mouse.x);
	frac->origin.b = info->mouse.y + (info->y_range / PIXELS_Y) * (frac->origin.b - info->mouse.y);
			
}