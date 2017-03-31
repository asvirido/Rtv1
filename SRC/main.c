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

void	init_demo(t_sphere *sphere, t_ray *ray)
{
	// INIT SPHERE
	sphere->radius = 100;
	sphere->radius_pow = sphere->radius * sphere->radius;
	sphere->position->x = 150;
	sphere->position->y = 150;
	sphere->position->z = 100;
	// INIT RAY
	ray->direction->z = 1;
	ray->origin->z = 0;
}

int		main(void)
{
	t_rtv1		*rtv1;

	rtv1 = create_rtv1();
	init_demo(rtv1->sphere, rtv1->ray);
	ray_tracing(rtv1);
	mlx_loop(MLX_MY);
	return (0);
}
