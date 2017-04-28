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

void	init_demo(t_rtv1 *rtv1)
{
	// INIT SPHERE 1
	rtv1->rt_obj[0].sphere->position->x = 200;
	rtv1->rt_obj[0].sphere->position->y = 10;
	rtv1->rt_obj[0].sphere->position->z = 400;
	rtv1->rt_obj[0].sphere->radius = 29;
	rtv1->rt_obj[0].sphere->radius_pow = rtv1->rt_obj[0].sphere->radius * rtv1->rt_obj[0].sphere->radius;
	rtv1->rt_obj[0].sphere->color = create_color(0x990077);

	rtv1->rt_obj[1].sphere->position->x = 400;//400
	rtv1->rt_obj[1].sphere->position->y = 400;//400
	rtv1->rt_obj[1].sphere->position->z = 300;//-250
	rtv1->rt_obj[1].sphere->radius = 150;
	rtv1->rt_obj[1].sphere->radius_pow = rtv1->rt_obj[1].sphere->radius * rtv1->rt_obj[1].sphere->radius;
	rtv1->rt_obj[1].sphere->color = create_color(0x009900);

	rtv1->rt_obj[2].sphere->position->x = 200;
	rtv1->rt_obj[2].sphere->position->y = 50;
	rtv1->rt_obj[2].sphere->position->z = 200;
	rtv1->rt_obj[2].sphere->radius = 50;
	rtv1->rt_obj[2].sphere->radius_pow = rtv1->rt_obj[2].sphere->radius * rtv1->rt_obj[2].sphere->radius;
	rtv1->rt_obj[2].sphere->color = create_color(0x000099);

	rtv1->rt_obj[3].plane->distance = -499;
	rtv1->rt_obj[3].plane->normal->x = 0;
	rtv1->rt_obj[3].plane->normal->y = 0;
	rtv1->rt_obj[3].plane->normal->z = 1;
	rtv1->rt_obj[3].plane->color = create_color(0x090077);

	rtv1->rt_obj[4].plane->distance = -600;
	rtv1->rt_obj[4].plane->normal->x = 0;
	rtv1->rt_obj[4].plane->normal->y = 1;
	rtv1->rt_obj[4].plane->normal->z = 0;
	rtv1->rt_obj[4].plane->color = create_color(0x4F4F4F);


	rtv1->rt_obj[5].cylinder->position->x = 100;
	rtv1->rt_obj[5].cylinder->position->y = 500;
	rtv1->rt_obj[5].cylinder->position->z = 400;
	rtv1->rt_obj[5].cylinder->direction->x = 0;
	rtv1->rt_obj[5].cylinder->direction->y = 0.707;
	rtv1->rt_obj[5].cylinder->direction->z = 0.707;
	rtv1->rt_obj[5].cylinder->radius = 100;
	rtv1->rt_obj[5].cylinder->radius_pow = rtv1->rt_obj[5].cylinder->radius * rtv1->rt_obj[5].cylinder->radius;
	rtv1->rt_obj[5].cylinder->color = create_color(0x991111);

	rtv1->rt_obj[6].cone->position->x = 590;
	rtv1->rt_obj[6].cone->position->y = 400;
	rtv1->rt_obj[6].cone->position->z = 200;
	rtv1->rt_obj[6].cone->direction->x = 0.10;
	rtv1->rt_obj[6].cone->direction->y = 0.90;
	rtv1->rt_obj[6].cone->direction->z = 0;
	rtv1->rt_obj[6].cone->color = create_color(0xC400AB);
	rtv1->rt_obj[6].cone->angle = 100;
	rtv1->rt_obj[6].cone->cone_cos_two = cos(rtv1->rt_obj[6].cone->angle) * cos(rtv1->rt_obj[6].cone->angle);
	rtv1->rt_obj[6].cone->cone_sin_two = sin(rtv1->rt_obj[6].cone->angle) * sin(rtv1->rt_obj[6].cone->angle);
	rtv1->rt_obj[6].cone->two_cone_cos_two = 2 * cos(rtv1->rt_obj[6].cone->angle) * cos(rtv1->rt_obj[6].cone->angle);
	rtv1->rt_obj[6].cone->two_cone_sin_two = 2 * sin(rtv1->rt_obj[6].cone->angle) * sin(rtv1->rt_obj[6].cone->angle);

	// INIT RAY
	rtv1->ray->direction->z = 0;
	rtv1->ray->direction->y = 0;
	rtv1->ray->direction->x = 0;
	rtv1->ray->origin->z = -400.99;
	rtv1->ray->origin->x = 400.99;
	rtv1->ray->origin->y = 400.99;
	// INIT LIGHT
	rtv1->light[0].position->x = 400;
	rtv1->light[0].position->y = 400;
	rtv1->light[0].position->z = -400;
	rtv1->light[0].color = create_color(0xFFFFFF);
//	rtv1->light[0].color.red = 249;
//	rtv1->light[0].color.blue = 252;
//	rtv1->light[0].color.green = 241;// = create_color(0xFFFFFF);
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
	new[5].cylinder = create_cylinder();
	new[5].plane = NULL;
	new[5].sphere = NULL;
	new[6].cone = create_cone();
	new[6].plane = NULL;
	new[6].sphere = NULL;
	new[6].cylinder = NULL;

	return (new);
}

t_light			*create_light(int size)
{
	t_light 	*new;
	int		i;

	i = 0;
	new = (t_light*)malloc(sizeof(t_light) * size + 10);
	while (i < size)
	{
		new[i].position = create_vector();
		i++;
	}
	return (new);
}


t_rtv1		*create_rtv1(void)
{
	t_rtv1		*rtv1;

	rtv1 = (t_rtv1*)malloc(sizeof(t_rtv1) + 1);
	rtv1->size_obj = 7;
	rtv1->size_light = 1;
	rtv1->ray = create_ray();
	rtv1->light_ray = create_ray();
	rtv1->rt_obj = create_rt_obj(rtv1->size_obj);
	rtv1->obj = object_mlx();
	rtv1->light = create_light(rtv1->size_light);
	rtv1->img = create_img(rtv1->obj);
	init_demo(rtv1);
	return (rtv1);
}
