/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:51:49 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/29 19:51:51 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_RT_H
# define CREATE_RT_H

# include "../Vector/vector.h"
# include "../mlx_src/mlx_src.h"

typedef struct	s_intersect
{
	double		t;
}				t_intersect;

typedef struct	s_light
{
	t_vector	*position;
	t_color		color;
}				t_light;

typedef struct	s_material
{
	double		reflection;
	t_color		color;
}				t_material;

typedef	struct	s_cylinder
{
	t_vector	*position;
	t_vector	*direction;
	t_color		color;
	double		radius;
	double		radius_pow;
}				t_cylinder;

typedef	struct	s_cone
{
	t_vector	*position;
	t_vector	*direction;
	t_color		color;
	double		angle;
	double		cone_cos_two;
	double		cone_sin_two;
	double		two_cone_cos_two;
	double		two_cone_sin_two;
}				t_cone;

typedef	struct	s_sphere
{
	t_vector	*position;
	t_color		color;
	double		radius;
	double		radius_pow;
}				t_sphere;

typedef struct	s_plane
{
	double		distance;
	t_color		color;
	t_vector	*normal;
}				t_plane;

typedef	struct	s_ray
{
	t_vector	*origin;
	t_vector	*direction;
	double		scalar_ray_direction;
}				t_ray;

typedef struct	s_screen
{
	t_vector	*ray;
	t_vector	*dir_normal;
}				t_screen;

t_sphere		*create_shpere(void);
t_ray			*create_ray(void);
t_plane			*create_plane(void);
t_cylinder		*create_cylinder(void);
t_cone			*create_cone(void);
t_screen		*create_map(void);
t_light			*create_all_light(int size);

#endif
