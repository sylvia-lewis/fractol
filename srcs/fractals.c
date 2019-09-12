/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:39:30 by sylewis           #+#    #+#             */
/*   Updated: 2019/09/12 15:32:34 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        func()
{
    while (ny < HEIGHT)
    {
        while (nx < WIDTH)
        {
            fractol->x = x;
            fractol->y = y;
            fractol(fractol);
            x++;
            nx++;
        }
        y++;
        ny++:
    }
    
}

void        mandelbrot()
{
    int     n;

    n = 0;
    while (n < MAX_ITER)
    {
        x = x * x - y * y + x1;
        y = 2 * x * y + y1;
        if (x * x + y * y > 4)
            break ;
        n++;
    }
    if (n == MAX_ITER)
    {
        return (0);
    }
    colour_pixel(n, structure);
}

void        colour_pixel()
{
    if (n > lim1)
        colour = COLOUR1;
    else if ( n > lim2)
        colour = COLOUR2;
}

void        julia(mouse)
{
    int     n;

    n = 0;
    while (n < MAX_ITER)
    {
        x = x * x - y * y + mouse->x;
        y = 2 * x * y + mouse->y;
        if (x * x + y * y > 4)
            break ;
        n++;
    }
    if (n == MAX_ITER)
    {
        return (0);
    }
    colour_pixel(n, structure);
}

void    fractol(t_info *info)
{
    int    n;
    int    x;
    int    y;

    if (info->fractol % 2 == 0) //JULIA
    {
        info->point.a = info->mouse.x;
        info->point.b = info->mouse.y;
    }
    if (info->fractol % 2 != 0) //MANDELBROT
    {
        info->point.a = pixel_location;
        info->point.b = pixel_location;
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
    colour_pixel(n, structure);
}