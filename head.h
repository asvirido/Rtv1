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
# define RAY_DIRECTION 			rtv1->ray->direction
# define L_RAY_ORIGIN 			rtv1->light_ray->origin
# define L_RAY_DIRECTION 		rtv1->light_ray->direction
# define RT							rtv1
# define SPHERE_POSITION 		sphere->position
# define SPHERE_RADIUS_POW 	sphere->radius_pow;
# define SIZE_OBJ 				rtv1->size_obj
# define SIZE_LIGHT 				rtv1->size_light
# define MLX_MY					rtv1->obj->mlx
# define WIN_MY					rtv1->obj->win
# define X 							val.ray.x
# define Y 							val.ray.y
# define Z 							val.ray.z

typedef struct	s_object
{
	t_sphere 		*sphere;
	t_plane 			*plane;
	t_cylinder 		*cylinder;
	t_cone			*cone;
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

typedef struct s_val_intersect
{
	int      i;
	int      num_obj;
	int      hit;
}					t_val_intersect;

typedef struct s_val_vector
{
	t_vector		point;
	t_vector		n_point;
	t_vector		tmp;
	t_color		color;
	t_vector		ray;
}					t_val_vector;

typedef struct	s_rtv1
{
	t_mlx			*obj;
	t_img			*img;
	t_ray 			*ray;
	t_ray			*light_ray;
	t_object		*rt_obj;
	t_light			*light;
	int				x;
	int				y;
	int				size_obj;
	int				size_light;
	int				debag;
}				t_rtv1;

t_rtv1	*create_rtv1(void);

void		ray_tracing(t_rtv1 *rtv1);

t_color  intersect(t_rtv1 *rtv1);
int 		intersect_ray_sphere(t_ray *ray, t_sphere *sphere, double *t);
int 		intersect_ray_plane(t_ray *ray, t_plane *plane, double *t);
int		intersect_ray_cylinder(t_ray *ray, t_cylinder *cylinder, double *t);
int		intersect_ray_cone(t_ray *ray, t_cone *cone, double *t);

t_color 	get_color(t_rtv1 *rtv1, int num_obj);
void 		set_color(t_color *color, int red, int green, int blue);

int		destroy(void);
int		event_key(int keycode, t_rtv1 *rtv1);
int		event_mouse(int keycode, int x, int y, t_rtv1 *rtv1);

#endif
