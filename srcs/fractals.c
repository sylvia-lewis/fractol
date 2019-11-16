/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:39:30 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/16 18:37:53 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"
#include "math.h"

void	fractal_julia(t_info *info, int pix_x, int pix_y)
{
	int		n;
	double	x;
	double	y;
	double	temp;
	t_point	pt;

	pt.a = info->origin.a + info->x_range * (double)info->mouse.x
		/ (double)PIXELS_X;
	pt.b = info->origin.b + info->y_range * (double)info->mouse.y
		/ (double)PIXELS_Y;
	n = 0;
	x = info->origin.a + info->x_range * (double)pix_x / (double)PIXELS_X;
	y = info->origin.b + info->y_range * (double)pix_y / (double)PIXELS_Y;
	while (n < info->max_iter)
	{
		temp = x * x - y * y;
		y = 2 * x * y + pt.b;
		x = temp + pt.a;
		if (x * x + y * y > 4)
			break ;
		n++;
	}
	colour_pixel(n, pix_x, pix_y, info);
}

void	fractal_mjulia(t_info *info, int pix_x, int pix_y)
{
	int		n;
	double	x;
	double	y;
	double	temp;
	t_point	pt;

	n = 0;
	x = info->origin.a + info->x_range * (double)pix_x / (double)PIXELS_X;
	y = info->origin.b + info->y_range * (double)pix_y / (double)PIXELS_Y;
	pt.a = info->origin.a + info->x_range * (double)info->mouse.x
		/ (double)PIXELS_X;
	pt.b = info->origin.b + info->y_range * (double)info->mouse.y
		/ (double)PIXELS_Y;
	while (n < info->max_iter && x * x + y * y < 4)
	{
		temp = pow(x * x + y * y, (info->multi) / 2) * cos((info->multi)
			* atan2(y, x)) + pt.a;
		y = pow(x * x + y * y, (info->multi) / 2) * sin((info->multi)
			* atan2(y, x)) + pt.b;
		x = temp;
		n++;
	}
	colour_pixel(n, pix_x, pix_y, info);
}

void	burning(t_info *info, int pix_x, int pix_y)
{
	int		n;
	double	x;
	double	y;
	double	temp;
	t_point	pt;

	pt.a = info->origin.a + info->x_range * (double)pix_x / (double)PIXELS_X;
	pt.b = info->origin.b + info->y_range * (double)pix_y / (double)PIXELS_Y;
	n = 0;
	x = pt.a;
	y = pt.b;
	while (n < info->max_iter)
	{
		temp = x * x - y * y + pt.a;
		y = fabs(2 * x * y) + pt.b;
		x = fabs(temp);
		if (x * x + y * y > 4)
			break ;
		n++;
	}
	colour_pixel(n, pix_x, pix_y, info);
}

void	pain_aux_amandes(t_info *info, int pix_x, int pix_y)
{
	int		n;
	double	x;
	double	y;
	double	temp;
	t_point	pt;

	pt.a = info->origin.a + info->x_range * (double)pix_x / (double)PIXELS_X;
	pt.b = info->origin.b + info->y_range * (double)pix_y / (double)PIXELS_Y;
	n = 0;
	x = pt.a;
	y = pt.b;
	while (n < info->max_iter)
	{
		temp = x * x - y * y + pt.a;
		y = 2 * x * y + pt.b;
		x = temp;
		if (x * x + y * y > 4)
			break ;
		else
			n++;
	}
	colour_pixel(n, pix_x, pix_y, info);
}

void	fractal(t_info *info, int pix_x, int pix_y)
{
	if (info->fractal == 2)
		fractal_julia(info, pix_x, pix_y);
	else if (info->fractal == 4)
		fractal_mjulia(info, pix_x, pix_y);
	else if (info->fractal == 3)
		burning(info, pix_x, pix_y);
	else if (info->fractal == 1)
		pain_aux_amandes(info, pix_x, pix_y);
}
