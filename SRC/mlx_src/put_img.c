/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:16:15 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/31 12:16:17 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_src.h"

void 			put_img(t_img *img, int x, int y, t_color *color)
{
   int		pix;

   if ((y >= 0 && x >= 0) && (y < SIZE_Y && x < SIZE_X))
   {
   	pix = y * img->size_line + x * 4;
   	if (x < SIZE_Y * SIZE_X * 4)
   	{
   		img->line[pix] = color->blue;
   		img->line[pix + 1] = color->green;
   		img->line[pix + 2] = color->red;
   	}
   }
}
