/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:39:30 by sylewis           #+#    #+#             */
/*   Updated: 2019/06/19 17:58:02 by sylewis          ###   ########.fr       */
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

void    fractol()
{
    int     n;
    if (julia)
    {
        x1 = mouse->x;
        y1 = mouse->y;
    }
    if (mandelbrot)
    {
        x1 = pixel;
        y1 = pixel;
    }
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