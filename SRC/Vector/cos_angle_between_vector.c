/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cos_angle_between_vector.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:35:55 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/23 18:35:56 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double		cos_angle_between_vector(t_vector *a, t_vector *b)
{
	double	module_a;
	double	module_b;
	double	scalar_product;
	double	angle;

	module_a = module_vector(a);
	module_b = module_vector(b);
	scalar_product = scalar_vector(a,b);
	angle = scalar_product / (module_a * module_b);
	return (angle);  
}
