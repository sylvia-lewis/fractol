/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:39:30 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/12 17:58:55 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        colour_pixel(int n, int x, int y, t_info *info)
{
    
    if (n != MAX_ITER)
    {
        ft_putnbr(n);
        ft_putchar('\n');
        mlx_pixel_put(info->mlx_ptr, info->win_ptr, x, y, 0xfffff);
    }

/*
    if (n > LIMIT_2)
    {
        *(int*)frac.img->string + x + y * PIXELS_X * 4 = COLOUR1;
        
    }
    else if ( n > LIMIT_1)
        frac.img->string = COLOUR2;
        */
}


void        func(t_info *info)
{
    int y;
    int x;

    x = 0;
    y = 0;
    while (y < PIXELS_Y)
    {
        while (x < PIXELS_X)
        {
            fractal(info, x, y);
            info->working_pixel.a += info->x_range / PIXELS_X;
            x++;
        }
        info->working_pixel.a = info->origin.a;
        info->working_pixel.b -= info->y_range / PIXELS_Y;
        x = 0;
        y++;
    }
    
}

void    fractal(t_info *info, int pix_x, int pix_y)
{
    int    n;
    double x;
    double y;

    if (info->fractal == 2) //JULIA
    {
        info->point.a = info->mouse.x;
        info->point.b = info->mouse.y;
    }
    if (info->fractal == 1) //MANDELBROT
    {
        info->point.a = info->working_pixel.a;
        info->point.b = info->working_pixel.b;
    }
    n = 0;
    x = info->point.a;
    y = info->point.b;
    while (n < MAX_ITER)
    {
        x = x * x - y * y + info->point.a;
        y = 2 * x * y + info->point.b;
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


/*
void    fractal(t_info *info)
{
    int    n;
    int    x;
    int    y;
    int    pix;
    int    piy;

    if (info->fractal == 2) //JULIA
    {
        info->point.a = info->mouse.x;
        info->point.b = info->mouse.y;
    }
    if (info->fractal == 1) //MANDELBROT
    {
        info->point.a = info->working_pixel.a;
        info->point.b = info->working_pixel.b;
    }
    n = 0;
    x = info->point.a;
    y = info->point.b;
    pix = 0;
    piy = 0;
    while (piy != PIXELS_Y)
    {
        while (pix != PIXELS_X)
        {
            while (n < MAX_ITER)
            {
                x = x * x - y * y + info->point.a;
                y = 2 * x * y + info->point.b;
                if (x * x + y * y > 4)
                    break ;
                n++;
            }
            colour_pixel(n, pix, piy, info);
            info->working_pixel.a += info->x_range / PIXELS_X;
            n = 0;
            x = info->working_pixel.a;
            y = info->working_pixel.b;
            pix++;
        }
        info->working_pixel.a = info->origin.a;
        pix = 0;
        info->working_pixel.b += info->y_range / PIXELS_Y;
        piy++;
    }    
}
*/