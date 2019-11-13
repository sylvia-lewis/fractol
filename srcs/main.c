/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:24:15 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/13 13:58:08 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		finish(t_info *info)
{
	ft_putendl_fd("end", 2);
	mlx_destroy_image(info->mlx_ptr, info->img.ptr);
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	exit(0);
}

void	init(t_info *info)
{
	info->origin.a = -2.0;
	info->origin.b = 2.0;
	info->working_pixel.a = info->origin.a;
	info->working_pixel.b = info->origin.b;
	info->x_range = 4.0;
	info->y_range = -4.0;
	info->max_iter = 30;
	if (info->fractal == 3 && info->multi == 0)
		info->multi = 3;
}

void	window(t_info *info)
{
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, PIXELS_X, PIXELS_Y,
		"Fract'ol by sylewis");
	mlx_hook(info->win_ptr, RED_CROSS, 0, finish, info);
	mlx_hook(info->win_ptr, KEY_PRESS, 0, key_press, info);
	mlx_hook(info->win_ptr, MOUSE_PRESS, 0, mouse_press, info);
	mlx_hook(info->win_ptr, MOUSE_RELEASE, 0, mouse_release, info);
	mlx_hook(info->win_ptr, MOUSE_MOVE, 0, mouse_move, info);
}

int		usage(void)
{
	ft_putstr("Usage: ./fractol 1 [Mandelbrot] || 2 [Julia] || ");
	ft_putstr("3 [Burning Ship] || 4 n [n-Julia] \n");
	return (0);
}

int		main(int argc, char **argv)
{
	t_info	info;

	if (argc < 2)
		return (usage());
	if (argc == 2 || argc == 3)
		info.fractal = ft_atoi(argv[1]);
	if (info.fractal == 4)
	{
		if (argc == 3)
			info.multi = ft_atoi(argv[2]);
		else
			return (usage());
	}
	window(&info);
	info.img.ptr = mlx_new_image(info.mlx_ptr, PIXELS_X, PIXELS_Y);
	info.img.string = mlx_get_data_addr(info.img.ptr,
		&info.img.bpp, &info.img.s_l, &info.img.endian);
	init(&info);
	func(&info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
