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

# define RAY_ORIGIN 				ray->origin
# define RAY_DIRECTION 			ray->direction
# define RAY_ORIGIN_X			rtv1->ray->origin->x
# define RAY_ORIGIN_Y			rtv1->ray->origin->y
# define SPHERE_POSITION 		sphere->position
# define	PLANE_POSITION 		plane->position
# define	PLANE_NORMAL 			plane->normal
# define SPHERE_RADIUS_POW 	sphere->radius_pow;
# define SIZE_OBJ 				rtv1->size_obj
# define MLX_MY					rtv1->obj->mlx
# define WIN_MY					rtv1->obj->win


typedef struct	s_object
{
	t_sphere 		*sphere;
	t_plane 			*plane;
}				t_object;

typedef struct s_val_math
{
	t_vector		dist;
	double		a;
	double		b;
	double		c;
	double		d;
	double		t0;
	double		t1;
}					t_val_math;
typedef struct	s_rtv1
{
	t_mlx				*obj;
	t_img				*img;
	t_ray 			*ray;
	t_object			*rt_obj;
	int				size_obj;
}				t_rtv1;

t_rtv1	*create_rtv1(void);

void		ray_tracing(t_rtv1 *rtv1);

void   	intersect(t_rtv1 *rtv1);
int 		intersect_ray_sphere(t_ray *ray, t_sphere 	*sphere, double *t);
int 		intersect_ray_plane(t_ray *ray, t_plane *plane, double *t);
t_color 	get_color(t_rtv1 *rtv1, int num_obj);
void 		set_color(t_rtv1 *rtv1, int num_obj);

int		destroy(void);
int		event_key(int keycode, t_rtv1 *rtv1);
int		event_mouse(int keycode, int x, int y, t_rtv1 *rtv1);

#endif
