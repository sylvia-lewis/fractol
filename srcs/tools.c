/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:16:58 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/14 16:27:29 by sylewis          ###   ########.fr       */
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

void	func(t_info *info)
{
	int	y;
	int x;

	ft_bzero(info->img.string, PIXELS_X * PIXELS_Y * 4);
	x = 0;
	y = 0;
	while (y < PIXELS_Y)
	{
		while (x < PIXELS_X)
		{
			fractal(info, x, y);
			info->working_pixel.a = info->origin.a + info->x_range * x
				/ PIXELS_X;
			x++;
		}
		info->working_pixel.a = info->origin.a;
		info->working_pixel.b = info->origin.b + info->y_range * y
			/ PIXELS_Y;
		x = 0;
		y++;
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.ptr, 0, -1);
}

void	colour_pixel(int n, int x, int y, t_info *info)
{
	*(int*)(info->img.string + ((x + y * PIXELS_X) * 4)) = 0x03f2eb * (n + 1);
}
