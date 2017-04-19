/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:09:38 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/31 12:09:39 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

int	check_and_get_t_sphere(double *t, t_val_math val)
{
	if (val.d < 0)
		return (0);
	val.c = sqrt(val.d);
	val.t0 = (-val.b + val.c) / 2;
	val.t1 = (-val.b - val.c) / 2;
	if (val.t0 > val.t1)
		val.t0 = val.t1;
	if (val.t0 > 0)
	{
		*t = val.t0;
		return (1);
	}
	return (0);
}

int	intersect_ray_sphere(t_ray *ray, t_sphere *sphere, double *t)
{
	t_val_math	val;
	int			res;

	val.dist = subtraction_vector(RAY_ORIGIN, SPHERE_POSITION);
	val.a =  dot_vector(RAY_DIRECTION, RAY_DIRECTION);
	val.b = 2 * dot_vector(RAY_DIRECTION, &val.dist);
	val.c = dot_vector(&val.dist, &val.dist) - SPHERE_RADIUS_POW;
	val.d = val.b * val.b - 4 * val.a * val.c;
	res = check_and_get_t_sphere(t, val);
	return (res);
}
