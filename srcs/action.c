/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:24:08 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/12 14:31:58 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int keycode, t_info *info)
{
	if (keycode == SPACE)
	{
		if (info->fractal < 3)
			info->fractal++;
		else
			info->fractal = 1;
		func(info);
	}
	if (keycode == ENTER)
	{
		init(info);
		func(info);
	}
	if (keycode == ESC)
		finish(info, "ESC");
	return (0);
}

int		mouse_press(int button, int x, int y, t_info *info)
{
	info->mouse.x = x;
	info->mouse.y = y;
	info->mouse.button = button;
	if (info->mouse.button == UP_WHEEL)
		zoom_in(info);
	else if (info->mouse.button == DOWN_WHEEL)
		zoom_out(info);
	func(info);
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
	info->mouse.x = x;
	info->mouse.y = y;
	func(info);
	return (0);
}