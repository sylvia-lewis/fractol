/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:26:30 by sylewis           #+#    #+#             */
/*   Updated: 2019/09/12 15:37:42 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    colour_pixel(int n)
{
    mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img->ptr, 0, 0);
    
}
