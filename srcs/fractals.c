/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:39:30 by sylewis           #+#    #+#             */
/*   Updated: 2019/06/16 20:17:18 by sylewis          ###   ########.fr       */
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
    if (n > )
}

void        julia()
{
    
}