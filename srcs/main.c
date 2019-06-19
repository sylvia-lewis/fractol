/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:24:15 by sylewis           #+#    #+#             */
/*   Updated: 2019/06/18 13:54:24 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				finish(t_info *info, char *reason)
{
	if (info != NULL)
		free_info(info);
	if (*reason == '\0')
		ft_putendl("");
	else
		ft_putendl_fd(reason, 2);
	exit(0);
	return (0);
}

int     main(int argc, char **argv)
{
    mlx_hook(info->win_ptr, RED_CROSS, 0, finish, info);
	mlx_hook(info->win_ptr, KEY_PRESS, 0, key_press, info);
	mlx_hook(info->win_ptr, MOUSE_PRESS, 0, mouse_press, info);
	mlx_hook(info->win_ptr, MOUSE_RELEASE, 0, mouse_release, info);
	mlx_hook(info->win_ptr, MOUSE_MOVE, 0, mouse_move, info);
	update_display(info);
	mlx_loop(info->mlx_ptr);
    return (0);
}