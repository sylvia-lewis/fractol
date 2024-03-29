/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:55:39 by sylewis           #+#    #+#             */
/*   Updated: 2019/11/16 18:47:01 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define W_NAME "Fractol by sylewis"
# define PIXELS_X 1080
# define PIXELS_Y 1080
# define HUD_WID 400

# define LIMIT_1 1
# define LIMIT_2 2

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

# define UP_ARROW 126
# define DOWN_ARROW 0x7D
# define LEFT_ARROW 0x7B
# define RIGHT_ARROW 0x7C

typedef struct		s_point
{
	double			a;
	double			b;
}					t_point;

typedef struct		s_pix
{
	double			a;
	double			b;
	char			*colour;
}					t_pix;

typedef struct		s_mouse
{
	int				button;
	int				x;
	int				y;
}					t_mouse;

typedef struct		s_img
{
	void			*ptr;
	char			*string;
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

typedef struct		s_info
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_mouse	mouse;
	struct s_point	point;
	struct s_point	working_pixel;
	struct s_point	zoom_pixel;
	struct s_point	origin;
	int				fractal;
	int				multi;
	double			x_range;
	double			y_range;
	struct s_img	img;
	int				max_iter;
}					t_info;

typedef struct		s_thread
{
	struct s_info	*info;
	int				i;
}					t_thread;

int					key_press(int keycode, t_info *info);
int					mouse_press(int button, int x, int y, t_info *info);
int					mouse_release(int button, int x, int y, t_info *info);
int					mouse_move(int x, int y, t_info *info);
void				zoom_in(t_info *info);
void				zoom_out(t_info *info);
int					finish(t_info *info);
void				fractal(t_info *info, int x, int y);
void				colour_pixel(int n, int x, int y, t_info *info);
void				init(t_info *info);
void				update(t_info *info);

#endif
