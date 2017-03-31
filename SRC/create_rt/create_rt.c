/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:45:36 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/31 12:00:30 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

t_rtv1		*create_rtv1(void)
{
	t_rtv1		*rtv1;

	rtv1 = (t_rtv1*)malloc(sizeof(t_rtv1) + 1);
	rtv1->ray = create_ray();
	rtv1->sphere = create_shpere();
	rtv1->obj = object_mlx();
	rtv1->img = create_img(rtv1->obj);
	return (rtv1);
}
