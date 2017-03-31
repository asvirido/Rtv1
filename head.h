/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:00:34 by asvirido          #+#    #+#             */
/*   Updated: 2017/02/15 16:36:26 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# define RAD 3.14 / 180.0

# include <fcntl.h>
# include <stdio.h>
# include "SRC/mlx_src/mlx_src.h"
# include "SRC/create_rt/create_rt.h"
# define RAY_ORIGIN 				rtv1->ray->origin
# define SCALAR_RAY_DIR 		rtv1->ray->scalar_ray_direction
# define RAY_ORIGIN 				rtv1->ray->origin
# define RAY_ORIGIN_X			rtv1->ray->origin->x
# define RAY_ORIGIN_Y			rtv1->ray->origin->y
# define RAY_DIRECTION 			rtv1->ray->direction
# define SPHERE_POSITION 		rtv1->sphere->position
# define SPHERE_RADIUS_POW 	rtv1->sphere->radius_pow
# define MLX_MY					rtv1->obj->mlx
# define WIN_MY					rtv1->obj->win
typedef struct	s_rtv1
{
	t_mlx				*obj;
	t_img				*img;
	t_ray 			*ray;
	t_sphere 		*sphere;
}				t_rtv1;

t_rtv1	*create_rtv1(void);
void		ray_tracing(t_rtv1 *rtv1);
int 		intersect_ray_sphere(t_rtv1 *rtv1);
#endif
