/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray_cone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:29:15 by asvirido          #+#    #+#             */
/*   Updated: 2017/04/26 19:29:16 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../head.h"

static int	check_and_get_t_sphere(double *t, t_val_math val)
{
	if (val.d < 0)
		return (0);
	val.c = sqrtf(val.d);
	val.t0 = (-val.b + val.c) / (2 * val.a);
	val.t1 = (-val.b - val.c) / (2 * val.a);
	if (val.t0 > val.t1)
		val.t0 = val.t1;
	if (val.t0 > 1)
	{
		*t = val.t0;
		return (1);
	}
	return (0);
}

static void 	find_a_b_c(t_ray *ray, t_cone *cone, t_val_math *val)
{
	t_vector		delta_p;
	t_vector		mult;
	t_vector		sub_1;
	t_vector		sub_2;
	double		res_1;
   double      res_2;

	delta_p = subtraction_vector(ray->origin,cone->position);
	///////////////////////////////////////////////////sub_1
	res_1 = dot_vector(ray->direction,cone->direction);
	mult = scalar_vector(res_1,cone->direction);
	sub_1 = subtraction_vector(ray->direction,&mult);
	////////////////////////////////////////////////sub_2
	res_2 = dot_vector(&delta_p,cone->direction);
	mult = scalar_vector(res_2,cone->direction);
	sub_2 = subtraction_vector(&delta_p,&mult);
	//a b c
	val->a = cone->cone_cos_two * dot_vector(&sub_1,&sub_1) - cone->cone_sin_two * (res_1 * res_1);
	val->b = cone->two_cone_cos_two * dot_vector(&sub_1,&sub_2) - cone->two_cone_sin_two * (res_1 * res_2);
	val->c = cone->cone_cos_two * dot_vector(&sub_2,&sub_2) - cone->cone_sin_two * (res_2 * res_2);
}

int	intersect_ray_cone(t_ray *ray, t_cone *cone, double *t)
{
	t_val_math	   val;
	int			  res;

	res = 0;
	find_a_b_c(ray,cone,&val);
	val.d = val.b * val.b - 4 * val.a * val.c;
	res = check_and_get_t_sphere(t, val);
	return (res);
}
