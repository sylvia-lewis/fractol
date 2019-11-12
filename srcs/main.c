/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcabel <hcabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:24:15 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/12 19:10:54 by hcabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_info(t_info *info)
{
	(void)info;
}

int				finish(t_info *info, char *reason)
{
	if (info != NULL)
		free_info(info);
	if (*reason == '\0')
	{
		ft_putendl("");
	}
	else
	{
		ft_putendl_fd(reason, 2);
	}
	exit(0);
	return (0);
}

void	init(t_info *info)
{
	info->origin.a = -2.5;
	info->origin.b = 2.0;
	info->working_pixel.a = info->origin.a;
	info->working_pixel.b = info->origin.b;
	info->x_range = 4.0;
	info->y_range = -4.0;
}

int     main(int argc, char **argv)
{
    t_info	info;

	if (argc != 2)
	{
		ft_putstr("Usage: ./fractol 1 [Mandelbrot] / 2 [Julia] / 3 [Surprise me]\n");
		return (0);
	}
	if (argc == 2)
	{
		info.fractal = ft_atoi(argv[1]);
	}

	info.mlx_ptr = mlx_init();
	info.win_ptr = mlx_new_window(info.mlx_ptr, PIXELS_X, PIXELS_Y, "Fractol");

	mlx_hook(info.win_ptr, RED_CROSS, 0, finish, &info);
	mlx_hook(info.win_ptr, KEY_PRESS, 0, key_press, &info);
	mlx_hook(info.win_ptr, MOUSE_PRESS, 0, mouse_press, &info);
	mlx_hook(info.win_ptr, MOUSE_RELEASE, 0, mouse_release, &info);
	mlx_hook(info.win_ptr, MOUSE_MOVE, 0, mouse_move, &info);
	info.img.ptr = mlx_new_image(info.mlx_ptr, PIXELS_X, PIXELS_Y);
	info.img.string = mlx_get_data_addr(info.img.ptr,
		&info.img.bpp, &info.img.s_l, &info.img.endian);
	init(&info);
	func(&info);
	mlx_loop(info.mlx_ptr);
    return (0);
}
