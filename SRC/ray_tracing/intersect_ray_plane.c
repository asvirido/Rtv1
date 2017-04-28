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

   res = 0;
   val.d = dot_vector(plane->normal, ray->direction);
   if (val.d > 0.001)
   {
      val.a = (dot_vector(plane->normal, ray->origin));
      val.b = -(val.a + plane->distance);
      val.t0 = val.b / val.d;
      if (val.t0 > 3)
      {
         *t = val.t0;
         res = 1;
      }
   }
   return (res);
}
