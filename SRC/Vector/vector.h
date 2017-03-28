/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:01:23 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/22 18:01:25 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>

typedef	struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

t_vector	addition_vector(t_vector *a, t_vector *b);
double		cos_angle_between_vector(t_vector *a, t_vector *b);
double		module_vector(t_vector *a);
t_vector	multiplication_vector(t_vector *a, t_vector *b);
t_vector	product_vectors(t_vector *a, t_vector *b);
double		scalar_vector(t_vector *a, t_vector *b);
t_vector	subtraction_vector(t_vector *a, t_vector *b);

#endif