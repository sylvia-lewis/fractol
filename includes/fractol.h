/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:55:39 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/12 15:24:41 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define MAX_ITER 50
# define W_NAME "Fractol by sylewis"
# define PIXELS_X 1080
# define PIXELS_Y 1080
# define HUD_WID 400

# define LIMIT_1 1
# define LIMIT_2 2

# define COLOUR1 "red" ^^^^
# define COLOUR2 "blue" ^^^^^

# define UP_WHEEL 4
# define RIGHT_CLICK 2
# define DOWN_WHEEL 5
# define LEFT_CLICK 1

# define RED_CROSS 17
# define KEY_PRESS 2
# define MOUSE_PRESS 4
# define MOUSE_RELEASE 5
# define MOUSE_MOVE 6

# define SPACE 49
# define ENTER 36
# define ESC 53

typedef struct      s_point
{
    double          a;
    double          b;
}                   t_point;

typedef struct      s_pix
{
    double          a;
    double          b;
    char            *colour;
}                   t_pix;

typedef struct      s_mouse
{
    int             button;
    int             x;
    int             y;
}                   t_mouse;


typedef struct      s_img
{
    void            *ptr;
    char            *string;
}                   t_img;


typedef struct      s_info
{
    void            *mlx_ptr;
    void            *win_ptr;
    struct s_mouse  mouse;
    struct s_point  point;
    struct s_point  working_pixel;
    struct s_point  zoom_pixel;
    struct s_point  origin;
    int             fractal;
    double          x_range;
    double          y_range;
    struct s_img    img;
}                   t_info;

typedef struct s_frac
{
    struct s_img    img;
    struct s_point  point;
    struct s_pix    working_pixel;
    struct s_point  origin;
}                   t_frac;


int		key_press(int keycode, t_info *info);
int		mouse_press(int button, int x, int y, t_info *info);
int		mouse_release(int button, int x, int y, t_info *info);
int		mouse_move(int x, int y, t_info *info);
void	zoom_in(t_info *info);
void	zoom_out(t_info *info);
int				finish(t_info *info, char *reason);
void            func(t_info *info);
void    fractal(t_info *info, int x, int y);
void        colour_pixel(int n, int x, int y, t_info *info);
void	init(t_info *info);

#endif