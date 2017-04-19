/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:57:54 by asvirido          #+#    #+#             */
/*   Updated: 2017/04/14 16:57:55 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void   intersect(t_rtv1 *rtv1)
{
   int      i;
   int      hit;
   int      i_min;
   double   t_min;
   double   t;


   i = 0;
   i_min = -1;
   t_min = 20000.0f;
   while (i < SIZE_OBJ)
   {
      t = 20000.0f;
      if (rtv1->rt_obj[i].plane != NULL)
      {
         hit = intersect_ray_plane(rtv1->ray, rtv1->rt_obj[i].plane, &t);
      }
      else if (rtv1->rt_obj[i].sphere != NULL)
         hit = intersect_ray_sphere(rtv1->ray, rtv1->rt_obj[i].sphere, &t);
      if (RAY_ORIGIN_X == 629 && RAY_ORIGIN_Y == 531)
         printf("t = %f I =%d\n",t,i);
      if (hit != 0 && t < t_min)
      {
         t_min = t;
         i_min = i;
      }
      i++;
   }
    if (i_min != -1)
      set_color(rtv1, i_min);
}
