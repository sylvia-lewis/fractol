/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:55:39 by sylewis           #+#    #+#             */
/*   Updated: 2019/06/17 14:59:16 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct      s_complex
{
    double          a;
    double          b;
}                   t_complex;

typedef struct      s_mouse
{
    int             button;
    int             x;
    int             y;
}                   t_mouse;

typedef struct      s_img;
{
    void            *ptr;

}                   t_img;

typedef struct      s_info
{
    void            *mlx_ptr;
    void            *win_ptr;
}                   t_info;
