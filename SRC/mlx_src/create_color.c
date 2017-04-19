/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:42:21 by asvirido          #+#    #+#             */
/*   Updated: 2017/04/13 15:42:22 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_src.h"

t_color  create_color(int color)
{
   t_color  new;

   new.red = (color >> 16);
   new.green = (color >> 8) - (new.red << 8);
   new.blue = (color) - (new.red << 16) - (new.green << 8);;

   return (new);
}
