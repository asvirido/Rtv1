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

int   print_vector(t_vector *a)
{
   printf("a.x = [%f]\n",a->x);
   printf("a.y = [%f]\n",a->y);
   printf("a.z = [%f]\n",a->z);
   return (1);
}

int   check_intersect_object(t_rtv1 *rtv1, double *t, int i, t_ray *ray)
{
   int   res;
   if (RT->rt_obj[i].plane != NULL)
      res = intersect_ray_plane(ray, RT->rt_obj[i].plane, t);
   else if (RT->rt_obj[i].sphere != NULL)
      res = intersect_ray_sphere(ray, RT->rt_obj[i].sphere, t);
   else if (RT->rt_obj[i].cylinder != NULL)
      res = intersect_ray_cylinder(ray, RT->rt_obj[i].cylinder, t);
   else if (RT->rt_obj[i].cone != NULL)
      res = intersect_ray_cone(ray, RT->rt_obj[i].cone, t);
   return (res);
}

t_vector	find_normal_cylinder(t_cylinder *cylinder, t_vector  *point)
{
	t_vector	a;
	t_vector	c;
	t_vector	tmp1;
	t_vector	new;
	double		b;

	a = subtraction_vector(point,cylinder->position);
	b = dot_vector(&a,cylinder->direction);
	c = scalar_vector(b,cylinder->direction);
	tmp1 = subtraction_vector(&c,&a);
	new = division_vector(&tmp1, cylinder->radius);
	return (new);
}

t_vector    find_normal_cone(t_cone *cone, t_vector  *point)
{
   t_vector b;
   t_vector c;
   t_vector d;
   t_vector v;
   t_vector new;
   double   a;

   b = subtraction_vector(point,cone->position);
   a = dot_vector(&b,cone->direction);
   c = scalar_vector(a,cone->direction);
   c = addition_vector(cone->position,&c);
   c = subtraction_vector(point,cone->position);
   d = product_vectors(&c,&b);
   v = product_vectors(&b,&d);
   a = module_vector(&v);
   new = division_vector(&v, a);
   return (new);
}

t_vector    get_intersect_normal(t_rtv1 *rtv1, int num_obj, t_vector *point)
{
   t_vector    normal;

   if (RT->rt_obj[num_obj].sphere != NULL)
      normal = normal_vector(RT->rt_obj[num_obj].sphere->position,point);
   else if (RT->rt_obj[num_obj].plane != NULL)
      normal = *RT->rt_obj[num_obj].plane->normal;
   else if (RT->rt_obj[num_obj].cylinder != NULL)
      normal = find_normal_cylinder(RT->rt_obj[num_obj].cylinder,point);
   else if (RT->rt_obj[num_obj].cone != NULL)
      normal = find_normal_cone(RT->rt_obj[num_obj].cone,point);
   return (normal);
}

t_vector  find_point_intersect(t_rtv1 *rtv1, double *t, int num_obj)
{
   t_vector    new_point;
   t_vector    scale;

   scale = scalar_vector(*t, RAY_DIRECTION);
   new_point = addition_vector(&scale, RAY_ORIGIN);
   return (new_point);
}

int     sub_intersect(t_rtv1 *rtv1, double *t)
{
   t_val_intersect   val;
   t_val_math        val_t;
   t_color           color;

   val.i = 0;
   val.num_obj = -1;
   while (val.i < SIZE_OBJ)
   {
      val_t.t1 = 20000.0f;
      val.hit = check_intersect_object(RT, &val_t.t1, val.i, RT->light_ray);
      if (val.hit && val_t.t1 < *t)
         return (0);
      val.i++;
   }
   return (1);
}

t_color rt_light(t_rtv1 *rtv1, double *t_min, int num_obj)
{
   t_val_vector   val;
   t_color        color;
   double         shad;
   double         t;
   int            hit;
   int            i;

   i = 0;
   val.point = find_point_intersect(RT, t_min, num_obj);
   val.n_point = get_intersect_normal(RT, num_obj, &val.point);
   color = get_color(RT, num_obj);
   while (i < SIZE_LIGHT)
   {
      val.tmp = normal_vector(RT->light[i].position, &val.point);
      set_vector(L_RAY_ORIGIN, &val.point);
      set_vector(L_RAY_DIRECTION, &val.tmp);

      shad = cos_angle_between_vector(&val.n_point, &val.tmp);
      val.tmp = subtraction_vector(RT->light[i].position, &val.point);
      t = module_vector(&val.tmp);

      hit = sub_intersect(RT, &t);
      if (hit == 0 || shad >= 0)
      {
			color.red = 0.3 * color.red;
			color.green = 0.3 * color.green;
			color.blue = 0.3 * color.blue;
			//color.trans = 110 * shad;//* (shad >= 0 ? (pow(shad,2)) : 1);
      }
	  else
	  {
		  color.red += (RT->light[i].color.red - color.red) * pow(fabs(shad),12);
		  color.blue += (RT->light[i].color.blue - color.blue) * pow(fabs(shad),12);
		  color.green += (RT->light[i].color.green - color.green) * pow(fabs(shad),12);
		 // color.trans = 220 * (shad >= 0 ? (pow(fabs(shad),5)) : 1);
	  }
      i++;
   }
   return (color);
}

t_color     intersect(t_rtv1 *rtv1)
{
	t_val_intersect	val;
	t_val_math		val_t;
	t_color			color;

	val.i = 0;
	val.num_obj = -1;
	val_t.t0 = 20000.0f;
	while (val.i < SIZE_OBJ)
	{
		val_t.t1 = 20000.0f;
		val.hit = check_intersect_object(RT, &val_t.t1, val.i, RT->ray);
		if (val.hit != 0 && val_t.t1 < val_t.t0)
		{
			val_t.t0 = val_t.t1;
			val.num_obj = val.i;
		}
		val.i++;
  	}
	if (val.num_obj != -1)
		color = get_color(RT,val.num_obj);//rt_light(RT, &val_t.t0, val.num_obj);
//	if (val.num_obj != -1)
//		color = rt_light(RT, &val_t.t0, val.num_obj);
//	else
//		set_color(&color,255,255,255);
	return (color);
}

//      if (val.num_obj != -1)
//         color = get_color(RT,val.num_obj);//rt_light(RT, &val_t.t0, val.num_obj);
