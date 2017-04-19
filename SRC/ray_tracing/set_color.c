/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:30:53 by asvirido          #+#    #+#             */
/*   Updated: 2017/04/14 17:30:53 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void  set_color(t_rtv1 *rtv1, int num_obj)
{
   t_color color;

   color = get_color(rtv1, num_obj);
   put_img(rtv1->img,RAY_ORIGIN_X,RAY_ORIGIN_Y,&color);
}
