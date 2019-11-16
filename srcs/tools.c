/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:16:58 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/16 18:45:32 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

void	*func(void *thread_addr)
{
	t_thread	*thread;
	int			y;
	int			x;

	thread = (t_thread*)thread_addr;
	y = 0;
	while (y < PIXELS_Y)
	{
		x = 0;
		while (x < PIXELS_X)
		{
			if ((y * PIXELS_X + x) % 8 == thread->i)
				fractal(thread->info, x, y);
			x++;
		}
		y++;
	}
	pthread_exit(NULL);
	return ((void*)0);
}

void	colour_pixel(int n, int x, int y, t_info *info)
{
	if (n == info->max_iter)
		*(int*)(info->img.string + ((x + y * PIXELS_X) * 4)) = 0xffffff;
	else
		*(int*)(info->img.string + ((x + y * PIXELS_X) * 4)) =
			0x03f2eb * (n + 1);
}

int		create_threads(t_info *info)
{
	int			i;
	pthread_t	tid[8];
	t_thread	thread[8];
	int			ret;

	i = 0;
	while (i < 8)
	{
		thread[i].info = info;
		thread[i].i = i;
		ret = pthread_create(&(tid[i]), NULL, func, (void *)(&(thread[i])));
		if (ret)
			return (-1);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return (0);
}

void	update(t_info *info)
{
	ft_bzero(info->img.string, PIXELS_X * PIXELS_Y * 4);
	create_threads(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.ptr, 0, 0);
}
