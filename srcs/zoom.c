/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:46:23 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/16 18:46:29 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_info *info)
{
	info->max_iter += 1;
	info->zoom_pixel.a = info->origin.a + info->x_range * (double)info->mouse.x
		/ (double)PIXELS_X;
	info->zoom_pixel.b = info->origin.b + info->y_range * (double)info->mouse.y
		/ (double)PIXELS_Y;
	info->x_range *= 0.8;
	info->y_range *= 0.8;
	info->origin.a = info->zoom_pixel.a - (info->x_range / (double)PIXELS_X)
		* (info->mouse.x);
	info->origin.b = info->zoom_pixel.b - (info->y_range / (double)PIXELS_Y)
		* (info->mouse.y);
}

void	zoom_out(t_info *info)
{
	info->zoom_pixel.a = info->origin.a + info->x_range * (double)info->mouse.x
		/ (double)PIXELS_X;
	info->zoom_pixel.b = info->origin.b + info->y_range * (double)info->mouse.y
		/ (double)PIXELS_Y;
	info->x_range *= 1.2;
	info->y_range *= 1.2;
	info->origin.a = info->zoom_pixel.a - (info->x_range / (double)PIXELS_X)
		* (info->mouse.x);
	info->origin.b = info->zoom_pixel.b - (info->y_range / (double)PIXELS_Y)
		* (info->mouse.y);
}
