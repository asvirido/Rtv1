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

int 	intersect_ray_sphere(t_rtv1 *rtv1)
{
	double		a;
	double		b;
	double		c;
	double		discriminant;
	t_vector	dist;

	dist = subtraction_vector(RAY_ORIGIN, SPHERE_POSITION);
	a = SCALAR_RAY_DIR;
	b = 2 * scalar_vector(RAY_DIRECTION, &dist);
	c = scalar_vector(&dist, &dist) - SPHERE_RADIUS_POW;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	return (1);
}
