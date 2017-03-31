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

t_color  create_color(int color)
{
   t_color  new;

   new.red = (color >> 16);
   new.green = (color >> 8) - (new.red << 8);
   new.blue = (color) - (new.red << 16) - (new.green << 8);;

   return (new);
}

void	ray_tracing(t_rtv1 *rtv1)
{
	int     x;
	int     y;
	int     hit;
   t_color color;

   color = create_color(0xFF00AA);
	y = 0;
	SCALAR_RAY_DIR = scalar_vector(RAY_DIRECTION, RAY_DIRECTION);
	while (y < SIZE_Y)
	{
		x = 0;
		RAY_ORIGIN_Y = y;
		while (x < SIZE_X)
		{
			RAY_ORIGIN_X = x;
			hit = intersect_ray_sphere(rtv1);
			if (hit != 0)
				put_img(rtv1->img,x,y,&color);
			x++;
		}
		y++;
	}
   PUT_IMG_WIN(MLX_MY, WIN_MY, rtv1->img->img, 0, 0);
}
