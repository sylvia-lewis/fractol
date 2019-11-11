/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:24:08 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/11 17:46:30 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int keycode, t_info *info)
{
	if (keycode == SPACE)
		info->fractal += 1; 
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
		return (0);
		//zoom(info);
	else if (info->mouse.button == DOWN_WHEEL)
		return (0);
		//zoom(info);
	//display_update_view(info);
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
	//display_update_view(info);
	return (0);
}