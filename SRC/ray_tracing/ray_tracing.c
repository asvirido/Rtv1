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

void	ray_tracing(t_rtv1 *rtv1)
{
   int     i;
   
	while (RAY_ORIGIN_Y < SIZE_Y)
	{
		RAY_ORIGIN_X = 0;
		while (RAY_ORIGIN_X < SIZE_X)
      {
         intersect(rtv1);
         RAY_ORIGIN_X++;
      }
		RAY_ORIGIN_Y++;
	}
   PUT_IMG_WIN(MLX_MY, WIN_MY, rtv1->img->img, 0, 0);
}
