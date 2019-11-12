/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcabel <hcabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:39:30 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/12 19:16:52 by hcabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"
#include "math.h"

void        colour_pixel(int n, int x, int y, t_info *info)
{
    *(int*)(info->img.string + ((x + y * PIXELS_X) * 4)) = 0x03f2eb * n;
}


void        func(t_info *info)
{
    int y;
    int x;

    ft_bzero(info->img.string, PIXELS_X * PIXELS_Y * 4);
    x = 0;
    y = 0;
    while (y < PIXELS_Y)
    {
        while (x < PIXELS_X)
        {
            fractal(info, x, y);
            info->working_pixel.a = info->origin.a + info->x_range * x / PIXELS_X;
            x++;
        }
        info->working_pixel.a = info->origin.a;
        info->working_pixel.b = info->origin.b + info->y_range * y / PIXELS_Y;
        x = 0;
        y++;
    }
    mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.ptr, 0, 0);
}

void    fractal_julia(t_info *info, int pix_x, int pix_y)
{
    int    n;
    double x;
    double y;

    if (info->fractal == 2) //JULIA
    {
        info->point.a = info->origin.a + info->x_range * (double)info->mouse.x / (double)PIXELS_X;
        info->point.b = info->origin.b + info->y_range * (double)info->mouse.y / (double)PIXELS_Y;
    }
    n = 0;
    x = info->working_pixel.a;
    y = info->working_pixel.b;
    double temp;
    while (n < MAX_ITER)
    {
        temp = x * x - y * y;
        y = 2 * x * y + info->point.b;
        x = temp + info->point.a;
        if (x * x + y * y > 4)
            break ;
        n++;
    }
    if (n == MAX_ITER)
    {
        return ;
    }
    colour_pixel(n, pix_x, pix_y, info);
}

void    fractal_mjulia(t_info *info, int pix_x, int pix_y)
{
    int    n;
    double x;
    double y;

    if (info->fractal == 3) //JULIA
    {
        info->point.a = info->origin.a + info->x_range * (double)info->mouse.x / (double)PIXELS_X;
        info->point.b = info->origin.b + info->y_range * (double)info->mouse.y / (double)PIXELS_Y;
    }
    n = 0;
    x = info->working_pixel.a;
    y = info->working_pixel.b;
    double temp;
    while (n < MAX_ITER)
    {
        temp = pow(x * x + y * y, 2) * cos(n * atan2(y, x)) + info->point.a;
        y = pow(x * x + y * y, 2) * sin(n * atan2(y, x)) + info->point.b;
        x = temp;
        if (x * x + y * y > 2)
            break ;
        n++;
    }
    if (n == MAX_ITER)
    {
        return ;
    }
    colour_pixel(n, pix_x, pix_y, info);
}

void    fractal(t_info *info, int pix_x, int pix_y)
{
    int    n;
    double x;
    double y;

    if (info->fractal == 2) //JULIA
    {
        fractal_julia(info, pix_x, pix_y);
        return ;
    }
    if (info->fractal == 3) //JULIA
    {
        fractal_mjulia(info, pix_x, pix_y);
        return ;
    }
    else if (info->fractal == 1) //MANDELBROT
    {
        info->point.a = info->working_pixel.a;
        info->point.b = info->working_pixel.b;
    }
    n = 0;
    x = info->point.a;
    y = info->point.b;
    double temp;
    while (n < MAX_ITER)
    {
        temp = x * x - y * y + info->point.a;
        y = 2 * x * y + info->point.b;
        x = temp;
        if (x * x + y * y > 4)
            break ;
        n++;
    }
    if (n == MAX_ITER)
    {
        return ;
    }
    colour_pixel(n, pix_x, pix_y, info);
}

