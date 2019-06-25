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

typedef struct      s_img
{
    void            *ptr;

};

typedef struct      s_info
{
    void            *mlx_ptr;
    void            *win_ptr;
}                   t_info;