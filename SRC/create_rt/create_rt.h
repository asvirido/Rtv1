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

typedef	struct	s_sphere
{
	t_vector	*position;
	double		radius;
	double		radius_pow;
}				t_sphere;

typedef	struct	s_ray
{
	t_vector	*origin;
	t_vector	*direction;
	double 		scalar_ray_direction;
}				t_ray;


t_sphere	*create_shpere(void);
t_ray		*create_ray(void);

#endif