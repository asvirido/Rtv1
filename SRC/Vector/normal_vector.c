/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 21:39:32 by asvirido          #+#    #+#             */
/*   Updated: 2017/04/19 21:39:33 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector normal_vector(t_vector *ray, t_vector *origin)
{
   t_vector    v;
   double      lenght;
   t_vector    new;

   v = subtraction_vector(ray, origin);
   lenght = module_vector(&v);
   new = division_vector(&v, lenght);
   return (new);
}
