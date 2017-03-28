/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:17:55 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/22 20:17:57 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	addition_vector(t_vector *a, t_vector *b)
{
	t_vector	c;

	c.x = a->x + b->x;
	c.y = a->y + b->y; 
	c.z = a->z + b->z;
	return (c);  
}
