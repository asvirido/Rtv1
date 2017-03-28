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
# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "SRC/Vector/vector.h"
# include "SRC/mlx_src/mlx_src.h"

typedef struct	s_rtv1
{
	t_mlx	*obj;
	t_img	*img;
}				t_rtv1;

typedef	struct	s_sphere
{
	t_vector	*position;
	double		radius;
}				t_sphere;

typedef	struct	s_ray
{
	t_vector	*origin;
	t_vector	*direction;
}				t_ray;

#endif
