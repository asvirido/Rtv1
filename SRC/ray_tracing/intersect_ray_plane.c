/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray_plane.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:26:40 by asvirido          #+#    #+#             */
/*   Updated: 2017/04/13 19:26:40 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

int   intersect_ray_plane(t_ray *ray, t_plane *plane, double *t)
{
   t_val_math  val;
   int         res;

   val.b = dot_vector(PLANE_NORMAL, RAY_DIRECTION);
   if (val.b == 0)
      res = 0;
   else
   {
      val.dist = subtraction_vector(PLANE_POSITION, RAY_ORIGIN);
      val.a = dot_vector(PLANE_NORMAL, &val.dist);
      val.t0 = val.a / val.b;
      res = ((val.t0 < 0) ? 0 : 1);
      if (res == 1)
         *t = val.t0;
   }
   printf("b %f\n",val.b);
   return (res);
}
