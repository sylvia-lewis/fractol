/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:39:30 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/09 18:37:10 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        func()
{
    while (ny < HEIGHT)
    {
        while (nx < WIDTH)
        {
            fractal->x = x;
            fractal->y = y;
            fractal(fractal);
            x++;
            nx++;
        }
        y++;
        ny++:
    }
    
}

void        colour_pixel(int n, t_info *info)
{
    if (n > lim1)
        info-> = COLOUR1;
    else if ( n > lim2)
        info->img.colour = COLOUR2;
}

void    fractal(t_info *info)
{
    int    n;
    int    x;
    int    y;

    if (info->fractal % 2 == 0) //JULIA
    {
        info->point.a = info->mouse.x;
        info->point.b = info->mouse.y;
    }
    if (info->fractal % 2 != 0) //MANDELBROT
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
        return (0);
    }
    colour_pixel(n, info->img.string);
    if (info->working_pixel.a != PIXELS_X)
        info->working_pixel.a++;
    else if (info->working_pixel.b != PIXELS_Y)
    {
        info->working_pixel.a = 0;
        info->working_pixel.b++;
    }
    else
    {
        STOP;
    }
    
    
}