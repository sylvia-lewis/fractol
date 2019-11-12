/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:16:58 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/12 15:05:46 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"
#include "stdio.h"


/*
	coords at (0,0) + range
	eg start at -2,2 range 3.7 * 4.2 => end 1.7,-2.2
	go to next pixel => (0,0) + (range/no. pix)
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
*/


void	zoom_in(t_info *info)
{
	printf("old x range = %f\n", info->x_range);
	printf("old y range = %f\n", info->y_range);
	printf("old a origin = %f\n", info->origin.a);
	printf("old b origin = %f\n", info->origin.b);
	
	info->x_range *= 0.99;
	info->y_range *= 0.99;

	info->zoom_pixel.a = info->origin.a + info->x_range * (double)info->mouse.x / (double)PIXELS_X;
	info->zoom_pixel.b = info->origin.b + info->y_range * (double)info->mouse.y / (double)PIXELS_Y;
	info->origin.a = info->zoom_pixel.a - (info->x_range / (double)PIXELS_X) * (info->mouse.x);
	info->origin.b = info->zoom_pixel.b - (info->y_range / (double)PIXELS_Y) * (info->mouse.y);
printf("x range = %f\n", info->x_range);
	printf("y range = %f\n", info->y_range);
	printf("a origin = %f\n", info->origin.a);
	printf("b origin = %f\n", info->origin.b);
}

void	zoom_out(t_info *info)
{
	printf("old x range = %f\n", info->x_range);
	printf("old y range = %f\n", info->y_range);
	printf("olda origin = %f\n", info->origin.a);
	printf("old b origin = %f\n", info->origin.b);
	
	info->x_range *= 1.01;
	info->y_range *= 1.01;

	info->zoom_pixel.a = info->origin.a + info->x_range * (double)info->mouse.x / (double)PIXELS_X;
	info->zoom_pixel.b = info->origin.b + info->y_range * (double)info->mouse.y / (double)PIXELS_Y;
	info->origin.a = info->zoom_pixel.a + (info->x_range / (double)PIXELS_X) * (double)(info->mouse.x);
	info->origin.b = info->zoom_pixel.b + (info->y_range / (double)PIXELS_Y) * (double)(info->mouse.y);
	printf("x range = %f\n", info->x_range);
	printf("y range = %f\n", info->y_range);
	printf("a origin = %f\n", info->origin.a);
	printf("b origin = %f\n", info->origin.b);
	
}