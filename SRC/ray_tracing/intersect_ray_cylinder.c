/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray_cylinder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 20:01:51 by asvirido          #+#    #+#             */
/*   Updated: 2017/04/25 20:01:51 by asvirido         ###   ########.fr       */
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

void 	find_a_b_c(t_ray *ray, t_cylinder *cylinder, t_val_math *val)
{
	t_vector		delta_p;
	t_vector		tmp;
	t_vector		sub_1;
	t_vector		sub_2;
	double		res;

	delta_p = subtraction_vector(ray->origin,cylinder->position);
	//sub_1
	res = dot_vector(ray->direction,cylinder->direction);
	tmp = scalar_vector(res,cylinder->direction);
	sub_1 = subtraction_vector(ray->direction,&tmp);
	//sub_2
	res = dot_vector(&delta_p,cylinder->direction);
	tmp = scalar_vector(res,cylinder->direction);
	sub_2 = subtraction_vector(&delta_p,&tmp);
	//a b c
	val->a = dot_vector(&sub_1,&sub_1);
	val->b = 2 * dot_vector(&sub_1,&sub_2);
	val->c = dot_vector(&sub_2,&sub_2) - cylinder->radius_pow;
}

int	intersect_ray_cylinder(t_ray *ray, t_cylinder *cylinder, double *t)
{
	t_val_math	   val;
	int			  res;

	res = 0;
	find_a_b_c(ray,cylinder,&val);
	val.d = val.b * val.b - 4 * val.a * val.c;
	res = check_and_get_t_sphere(t, val);
	return (res);
}
