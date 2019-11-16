/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:24:08 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/16 17:59:22 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		arrows(int keycode, t_info *info)
{
	if (keycode == RIGHT_ARROW)
	{
		info->origin.a -= info->x_range / 100;
		update(info);
	}
	if (keycode == LEFT_ARROW)
	{
		info->origin.a += info->x_range / 100;
		update(info);
	}
	if (keycode == UP_ARROW)
	{
		info->origin.b += info->y_range / 100;
		update(info);
	}
	if (keycode == DOWN_ARROW)
	{
		info->origin.b -= info->y_range / 100;
		update(info);
	}
	return (0);
}

int		key_press(int keycode, t_info *info)
{
	ft_bzero(info->img.string, PIXELS_X * PIXELS_Y * 4);
	if (keycode == SPACE)
	{
		if (info->fractal < 3)
			info->fractal++;
		else
			info->fractal = 1;
		update(info);
	}
	if (keycode == ENTER)
	{
		init(info);
		update(info);
	}
	if (keycode == ESC)
		finish(info);
	if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW ||
		keycode == UP_ARROW || keycode == DOWN_ARROW)
		return (arrows(keycode, info));
	if (keycode == 0x00)
	{
		info->max_iter++;
		update(info);
	}
	return (0);
}

int		mouse_press(int button, int x, int y, t_info *info)
{
	ft_bzero(info->img.string, PIXELS_X * PIXELS_Y * 4);
	info->mouse.x = x;
	info->mouse.y = y;
	info->mouse.button = button;
	if (info->mouse.button == UP_WHEEL)
		zoom_in(info);
	else if (info->mouse.button == DOWN_WHEEL)
		zoom_out(info);
	update(info);
	return (0);
}

int		mouse_release(int button, int x, int y, t_info *info)
{
	(void)button;
	(void)x;
	(void)y;
	info->mouse.button = 0;
	return (0);
}

int		mouse_move(int x, int y, t_info *info)
{
	if (info->fractal == 2 || info->fractal == 4)
	{
		info->mouse.x = x;
		info->mouse.y = y;
		update(info);
	}
	return (0);
}
