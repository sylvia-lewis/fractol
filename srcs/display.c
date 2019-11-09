/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:05:35 by sylewis           #+#    #+#             */
/*   Updated: 2019/10/10 17:51:04 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_init(t_info *info)
{
	int     bpp;
	int     size_line;
	int     endian;
	void    *mlx_ptr = mlx_init();
	void    *img_ptr = mlx_new_image(mlx_ptr, PIXELS_X, PIXELS_Y); 
	char    *img_data =  mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
}

void	display_update_view(t_info *info)
{
	

	(void)info;
}