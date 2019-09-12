/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:24:08 by sylewis           #+#    #+#             */
/*   Updated: 2019/09/12 15:28:18 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int keycode, t_info *info)
{
	if (keycode == SPACE)
		info->fractol += 1; 
	return (0);
}

int		mouse_press(int button, int x, int y, t_info *info)
{
	info->mouse.button = button;
	if (info->mouse.button == UP_WHEEL)
		[zoom function]
	else if (info->mouse.button == DOWN_WHEEL)
		[reverse zoom]
	display_update_view(info);
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
	display_update_view(info);
	return (0);
}