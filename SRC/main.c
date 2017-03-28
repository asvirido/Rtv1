/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:14:08 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/16 19:14:08 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int 	intersect_ray_sphere(t_ray *ray, t_sphere *sphere)
{
	double		a;
	double		b;
	double		c;
	double		discriminant;
	t_vector	dist;

	dist = subtraction_vector(ray->origin, sphere->position);
	a = scalar_vector(ray->direction, ray->direction);
	b = 2 * scalar_vector(ray->direction, &dist);
	c = scalar_vector(&dist, &dist) - (sphere->radius * sphere->radius);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	return (1);
}

void	init_demo(t_sphere *sphere, t_ray *ray)
{
	// INIT SPHERE 
	sphere->radius = 3;
	sphere->position->x = 30;
	sphere->position->y = 30;
	sphere->position->z = 30;
	// INIT RAY
	ray->direction->x = 0;
	ray->direction->y = 0;
	ray->direction->z = 1;
	ray->origin->x = 0;
	ray->origin->y = 0;
	ray->origin->z = 0;
}

int		main(void)
{
	int 		x;
	int 		y;
	int			hit;
	t_sphere 	*sphere;
	t_ray		*ray;

	ray = (t_ray*)malloc(sizeof(t_ray) + 1);
		ray->origin = (t_vector*)malloc(sizeof(t_vector) + 1);
		ray->direction = (t_vector*)malloc(sizeof(t_vector) + 1);
	sphere = (t_sphere*)malloc(sizeof(t_sphere) + 1);
		sphere->position = (t_vector*)malloc(sizeof(t_vector) + 1);

	init_demo(sphere, ray);

	y = 0;
	while (y < SIZE_Y)
	{
		x = 0;
		ray->origin->y = y;
		while (x < SIZE_X)
		{
			ray->origin->x = x;
			hit = intersect_ray_sphere(ray, sphere);
			if (hit == 0)
				printf("+++");
			else
				printf("---");
			x++;
		}
		printf("\n");
		y++;
	}
	return (0);
}
