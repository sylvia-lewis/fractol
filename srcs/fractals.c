/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:39:30 by sylewis           #+#    #+#             */
/*   Updated: 2019/06/18 17:15:17 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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