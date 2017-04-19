/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:45:36 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/31 12:00:30 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	init_demo(t_object *rt_obj, t_ray *ray)
{
	// INIT SPHERE 1
	rt_obj[0].sphere->position->x = 400;
	rt_obj[0].sphere->position->y = 400;
	rt_obj[0].sphere->position->z = 400;
	rt_obj[0].sphere->radius = 30 / (0.005 * rt_obj[0].sphere->position->z);
	rt_obj[0].sphere->radius_pow = rt_obj[0].sphere->radius * rt_obj[0].sphere->radius;
	rt_obj[0].sphere->color = create_color(0xFF00AA);

	rt_obj[1].sphere->position->x = 200;
	rt_obj[1].sphere->position->y = 300;
	rt_obj[1].sphere->position->z = 200;
	rt_obj[1].sphere->radius = 150 / (0.005 * rt_obj[1].sphere->position->z);
	rt_obj[1].sphere->radius_pow = rt_obj[1].sphere->radius * rt_obj[1].sphere->radius;
	rt_obj[1].sphere->color = create_color(0x00FF00);

	rt_obj[2].sphere->position->x = 400;
	rt_obj[2].sphere->position->y = 180;
	rt_obj[2].sphere->position->z = 180;
	rt_obj[2].sphere->radius = 50 / (0.005 * rt_obj[2].sphere->position->z);
	rt_obj[2].sphere->radius_pow = rt_obj[2].sphere->radius * rt_obj[2].sphere->radius;
	rt_obj[2].sphere->color = create_color(0x0000FF);

	rt_obj[3].plane->distance = 0;
	rt_obj[3].plane->normal->x = 0;
	rt_obj[3].plane->normal->y = 1;
	rt_obj[3].plane->normal->z = 0;
	rt_obj[3].plane->color = create_color(0x0F00AA);

	rt_obj[4].plane->distance = 30;
	rt_obj[4].plane->normal->x = 0;
	rt_obj[4].plane->normal->y = 0;
	rt_obj[4].plane->normal->z = -1;
	rt_obj[4].plane->color = create_color(0x2F2F2F);
	// INIT RAY
	ray->direction->z = 1;
	ray->direction->y = 0;
	ray->origin->z = -50;
}

t_object			*create_rt_obj(int size_obj)
{
	t_object 	*new;

	new = (t_object*)malloc(sizeof(t_object) * size_obj + 1);
	new[0].sphere = create_shpere();
	new[0].plane = NULL;
	new[1].sphere = create_shpere();
	new[1].plane = NULL;
	new[2].sphere = create_shpere();
	new[2].plane = NULL;
	new[3].plane = create_plane();
	new[3].sphere = NULL;
	new[4].plane = create_plane();
	new[4].sphere = NULL;
	return (new);
}

t_rtv1		*create_rtv1(void)
{
	t_rtv1		*rtv1;

	rtv1 = (t_rtv1*)malloc(sizeof(t_rtv1) + 1);
	rtv1->size_obj = 5;
	rtv1->ray = create_ray();
	rtv1->rt_obj = create_rt_obj(rtv1->size_obj);
	rtv1->obj = object_mlx();
	rtv1->img = create_img(rtv1->obj);
	init_demo(rtv1->rt_obj, rtv1->ray);
	return (rtv1);
}
