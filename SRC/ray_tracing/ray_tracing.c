/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:11:53 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/31 12:11:54 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void ft_free(t_rtv1 *rtv1, char *line)
{
   int      x;
   int      y;
   t_color  color;

   y = 0;
   color.red = 255;
   color.blue = 255;
   color.green = 255;
   color.trans = 255;
   while (y < SIZE_Y)
   {
      while (x < SIZE_X)
      {
         put_img(rtv1->img,x,y,&color);
         x++;
      }
      y++;
   }
}

void	ray_tracing(t_rtv1 *rtv1)
{
   t_val_vector   val;

   Y = 0;
   Z = 0;
   mlx_clear_window (MLX_MY,WIN_MY);
   while (Y < SIZE_Y)
	{
		X = 0;
		while (X < SIZE_X)
      {
         RT->x = X;
         RT->y = Y;
         val.tmp = normal_vector(&val.ray, RAY_ORIGIN);
         set_vector(RAY_DIRECTION, &val.tmp);
         val.color = intersect(rtv1);
         put_img(rtv1->img,X,Y,&val.color);
         X++;
      }
		Y++;
	}
   PUT_IMG_WIN(MLX_MY, WIN_MY, rtv1->img->img, 0, 0);
   ft_free(rtv1, rtv1->img->line);
}
